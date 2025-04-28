from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

import mariadb

from typing import List, Dict, Optional

app = FastAPI(title="E-Store API")

queries_dict: Dict[str, str] = {
    "Quali sono i registi presenti su Netflix?": "SELECT * FROM movies WHERE piattaforma_1 = 'Netflix' OR piattaforma_2 = 'Netflix'",
    "Elenca tutti i film di fantascienza.": "SELECT * FROM movies WHERE genere = 'Fantascienza'",
    "Quali registi hanno fatto più di un film?": "SELECT * FROM movies GROUP BY regista HAVING COUNT(*) > 1"
}

class Property(BaseModel):
    property_name: str
    property_value: str

class Film(BaseModel):
    item_type: str
    properties: List[Property]

class TableColumn(BaseModel):
    table_name: str
    table_column: str

class AddRowRequest(BaseModel):
    data_line: str

class AddRowResponse(BaseModel):
    success: bool
    message: str

def connect_to_db():
    # TODO: usare variabili d'ambiente del docker da cui si estrae lo user e la password con os. ... (come fa Luca)
    conn = mariadb.connect(
        host="db",
        port=3306,
        user="root",
        password="pass123",
        database="esonero_db"
    )
    return conn

def convert_to_sql(natural_lang_query: str) -> str:
    words = natural_lang_query.split(" ")
    if words[0] == "Elenca" and words[1] == "i": # TODO se uno cerca "Elenca i cazzi nel culo" entra lo stesso (usa una regex)
        anno = words[4].strip(".")
        sql_query = f"SELECT * FROM movies WHERE anno = {anno}"
    elif words[0] == "Quali" and words[1] == "film": # TODO se uno cerca "Quali film cazzi nel culo" entra lo stesso
        anni = words[10]
        sql_query = f"SELECT * FROM movies WHERE anno >= {anni}" 
    else:
        sql_query = queries_dict[natural_lang_query]
    return sql_query

def execute_query(connection: mariadb.Connection, query: str):
    cursor: mariadb.Cursor = connection.cursor()
    cursor.execute(query)

    results = cursor.fetchall()
    
    column_names = [column[0] for column in cursor.description]

    connection.commit()

    cursor.close()
    return (results, column_names)

# input: stringa che contiene una domanda in natural language
# output: risultato esecuzione query in json
@app.get("/search/{natural_lang_query}")
def get_search(natural_lang_query) -> List[Film]:
    conn = connect_to_db()

    sql_query = convert_to_sql(natural_lang_query)
    results, column_names = execute_query(conn, sql_query)
    print(results, '\n')

    conn.close()

    movies: List[Film] = []
    for result in results:
        properties: List[Property] = []
        for property, name in zip(result, column_names):
            properties.append(
                Property(
                    property_name=name,
                    property_value=str(property)
                )
            )
        movies.append(
            Film(
                item_type="film",
                properties=properties
            )
        )

    return movies

# input: nulla
# output: schema del database in json
@app.get("/schema_summary")
def get_schema_summary() -> List[TableColumn]:
    conn = connect_to_db()

    sql_tables_query = f"SELECT table_name FROM information_schema.tables WHERE table_schema = 'esonero_db'"
    
    results, _ = execute_query(conn, sql_tables_query)
    table_names = [row[0] for row in results]
    #print(table_names, '\n')

    schema: List[TableColumn] = []
    for table_name in table_names:
        sql_columns_query = f"SELECT * FROM {table_name} LIMIT 0"
        _, column_names = execute_query(conn, sql_columns_query)
        #print(column_names, '\n')
        for column_name in column_names:
            schema.append(
                TableColumn(
                    table_name=table_name,
                    table_column=column_name
                )
            )
    return schema


# input: data_line --> una tupla da inserire nel DB (una linea di dati separata da virgole)
# output: conferma dell'aggiunta nel DB
# Implementare gestione errori di formattazione 
@app.post("/add")
def add(data_line_request: AddRowRequest) -> AddRowResponse:
    data_line = data_line_request.data_line

    conn = connect_to_db()
    cursor = conn.cursor()

    table_name = "movies"
    data_to_insert = tuple(data_line.strip().split(","))
    print(data_to_insert, '\n')
    #data_to_insert = ('a', 'b', 1, 2, 'c', 'd', 'e')
    #data_to_insert = ('a', 'b')
    #sql_command = f"INSERT INTO {table_name} ({col1}, {col2}, {col3}) VALUES ({val1}, {val2}, {val3})"
    #sql_command = f"INSERT INTO {table_name} VALUES ({val1}, {val2}, {val3})"
    sql_command = f"INSERT INTO {table_name} (titolo, regista, eta_autore, anno, genere, piattaforma_1, piattaforma_2) VALUES (%s, %s, %s, %s, %s, %s, %s)"
    
    cursor.execute(sql_command, data_to_insert)

    conn.commit()

    cursor.close()
    conn.close()

    return AddRowResponse(
        success=True,
        message=f"Dajeroma dajee"
    )

#if __name__ == "__main__":
#    import uvicorn
#    uvicorn.run(app, host="127.0.0.1", port=8003)

    