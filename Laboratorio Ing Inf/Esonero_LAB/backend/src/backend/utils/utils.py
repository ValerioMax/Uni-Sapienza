from typing import List, Dict
import mariadb
import re

NOME_DATABASE = "esonero_db"

static_queries_dict: Dict[str, str] = {
    "Quali sono i registi presenti su Netflix?": "SELECT regista FROM movies WHERE piattaforma_1 = 'Netflix' OR piattaforma_2 = 'Netflix'",
    "Elenca tutti i film di fantascienza.": "SELECT titolo FROM movies WHERE genere = 'Fantascienza'",
    "Quali registi hanno fatto più di un film?": "SELECT regista FROM movies GROUP BY regista HAVING COUNT(*) > 1"
}

def connect_to_db():
    # TODO: usare variabili d'ambiente del docker da cui si estrae lo user e la password con os. ... (come fa Luca)
    conn = mariadb.connect(
        host="db",
        port=3306,
        user="root",
        password="pass123",
        database=NOME_DATABASE
    )
    return conn

def convert_to_sql(natural_lang_query: str) -> str: 
    pattern = r"^Elenca i film del (\d{4})\.$" # TODO: matcha solo anni da 4 cifre (es 234 non viene matchato)
    match = re.match(pattern, natural_lang_query)
    if match:
        anno = match.group(1)
        sql_query = f"SELECT titolo FROM movies WHERE anno = {anno}"
        return sql_query
    
    pattern = r"Quali film sono stati fatti da un regista di almeno (\d{1,3}) anni\?"
    match = re.match(pattern, natural_lang_query)
    if match:
        anni = match.group(1)
        sql_query = f"SELECT titolo FROM movies WHERE eta_autore >= {anni}" 
        return sql_query
    
    sql_query = static_queries_dict.get(natural_lang_query)
    return sql_query

def execute_query(connection: mariadb.Connection, query: str):
    cursor: mariadb.Cursor = connection.cursor()
    cursor.execute(query)

    results = cursor.fetchall()    
    column_names = [column[0] for column in cursor.description]

    connection.commit()

    cursor.close()
    return (results, column_names)

def get_query_item_type(column_names):
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

def check_data_line_format(data_line):
    pattern = r"^\s*.*\s*,\s*.*\s*,\s*(\d{1,3})?\s*,\s*(\d{4})?\s*,\s*.*\s*,\s*.*\s*,\s*.*\s*$"
    return re.match(pattern, data_line)
