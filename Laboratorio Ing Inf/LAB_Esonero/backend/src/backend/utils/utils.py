from typing import List, Dict, Match
import mariadb
import re
import os

# Definizioni per la connessione al database ottenute dalle variabili di ambiente impostate nel file docker-compose.yaml
DB_HOST = os.environ.get("DB_HOST")
DB_PORT = int(os.environ.get("DB_PORT"))
DB_USER = os.environ.get("DB_USER")
DB_PASSWORD = os.environ.get("DB_PASSWORD")
DB_NAME = os.environ.get("DB_NAME")

# Dizionario per fare mapping in query SQL per l'endpoint search/
static_queries_dict: Dict[str, str] = {
    "Quali sono i registi presenti su Netflix?": "SELECT regista FROM movies WHERE piattaforma_1 = 'Netflix' OR piattaforma_2 = 'Netflix'",
    "Elenca tutti i film di fantascienza.": "SELECT titolo FROM movies WHERE genere = 'Fantascienza'",
    "Quali registi hanno fatto più di un film?": "SELECT regista FROM movies GROUP BY regista HAVING COUNT(*) > 1"
}

# Regex per fare mapping in query SQL per l'endpoint search/
query1_pattern = r"^Elenca i film del (\d{4})\.$"
query2_pattern = r"Quali film sono stati fatti da un regista di almeno (\d{1,3}) anni\?"

# Definizione degli esiti che può avere il matching delle regex che gestiscono l'input dell'endopoint add/
DATA_LINE_FORMAT_OK = 1
DATA_LINE_FORMAT_ERROR = -1
DATA_LINE_FIELD_EMPTY_ERROR = -2

# Regex che gestiscono l'input dell'endopoint add/
data_line_check_pattern1 = r"^\s*[^,\s]+(\s+[^,\s]+)*\s*,\s*[^,\s]+(\s+[^,\s]+)*\s*,\s*(\d{1,3})?\s*,\s*(\d{4})?\s*," \
                            r"\s*[^,\s]+(\s+[^,\s]+)*\s*,\s*[^,\s]*(\s+[^,\s]+)*\s*,\s*[^,\s]*(\s+[^,\s]+)*\s*$"
data_line_check_pattern2 = r"^\s*[^,\s]*(\s+[^,\s]+)*\s*,\s*[^,\s]*(\s+[^,\s]+)*\s*,\s*(\d{1,3})?\s*,\s*(\d{4})?\s*," \
                            r"\s*[^,\s]*(\s+[^,\s]+)*\s*,\s*[^,\s]*(\s+[^,\s]+)*\s*,\s*[^,\s]*(\s+[^,\s]+)*\s*$"

def connect_to_db() -> mariadb.Connection:
    """ Si connette al database """

    conn: mariadb.Connection = mariadb.connect(
        host=DB_HOST,
        port=DB_PORT,
        user=DB_USER,
        password=DB_PASSWORD,
        database=DB_NAME
    )
    return conn

def convert_to_sql(natural_lang_query: str) -> str: 
    """
    Converte in query in linguaggio naturale in SQL.
    Usa un dizionario per le query statiche e delle regex per le query dinamiche
    """

    match = re.match(query1_pattern, natural_lang_query)
    if match:
        anno = match.group(1)
        sql_query = f"SELECT titolo FROM movies WHERE anno = {anno}"
        return sql_query
    
    match = re.match(query2_pattern, natural_lang_query)
    if match:
        anni = match.group(1)
        sql_query = f"SELECT titolo FROM movies WHERE eta_autore >= {anni}" 
        return sql_query
    
    sql_query = static_queries_dict.get(natural_lang_query)
    return sql_query

def execute_query(connection: mariadb.Connection, query: str):
    """ Esegue la query sul database a partire da una connessione con esso """

    cursor: mariadb.Cursor = connection.cursor()
    cursor.execute(query)

    results = cursor.fetchall()    
    column_names = [column[0] for column in cursor.description]

    connection.commit()

    cursor.close()
    return (results, column_names)

def get_query_item_type(column_names: List[str]) -> str:
    """
    Ritorna l'item_type da inserire nella classe Pydantic.
    Per aderire al tester usa item_type="film" per la colonna titolo e item_type="director" per la colonna regista.
    Nel caso venissero selezionate altre colonne assegna a item_type il nome della colonna stessa.
    """

    if len(column_names) == 1:
        column_name = column_names[0]
        if column_name == "titolo":
            item_type = "film"
        elif column_name == "regista":
            item_type = "director"
        else:
            item_type = column_name
        return item_type
    item_type = ""
    for column_name in column_names:
        item_type += f", {column_name}"
    return item_type

def check_data_line_format(data_line: str) -> Match[str]:
    """ 
    Controlla che il formato della linea inserita per l'endopoint add/ sia corretto.
    Controlla anche che venga inserito qualcosa nei campi di: titolo, regista, eta_autore, anno, genere 
    che devono essere NOT NULL in accordo con la definizione della tabella movies nel database.
    """

    match1 = re.match(data_line_check_pattern1, data_line)
    match2 = re.match(data_line_check_pattern2, data_line)

    if not match1 and match2:
        return DATA_LINE_FIELD_EMPTY_ERROR
    if not match1 and not match2:
        return DATA_LINE_FORMAT_ERROR
    return DATA_LINE_FORMAT_OK
