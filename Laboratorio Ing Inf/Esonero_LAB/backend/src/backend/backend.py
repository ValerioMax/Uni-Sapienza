from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import List, Dict
from .utils.utils import *
import mariadb

app = FastAPI()

class Property(BaseModel):
    property_name: str
    property_value: str

class Item(BaseModel):
    item_type: str
    properties: List[Property]

class TableColumn(BaseModel):
    table_name: str
    table_column: str

class AddRowRequest(BaseModel):
    data_line: str

class AddRowResponse(BaseModel):
    status: str

@app.get("/search/{natural_lang_query}")
def get_search(natural_lang_query) -> List[Item]:
    conn = connect_to_db()

    sql_query = convert_to_sql(natural_lang_query)
    if not sql_query:
        conn.close()
        raise HTTPException(status_code=422, detail="Formato query in linguaggio naturale invalido")

    query_results, column_names = execute_query(conn, sql_query)

    conn.close()

    """ Assumendo che vogliamo un item_type diverso dal nome della colonna dove si trova (es: 'director' invece che 'regista') """
    item_type = get_query_item_type(column_names)

    search_results: List[Item] = []
    for result in query_results:
        properties: List[Property] = []
        for index, column_name in enumerate(column_names):
            properties.append(
                Property(
                    property_name="name",
                    property_value=str(result[index])
                )
            )
        search_results.append(
                Item(
                    item_type=item_type,
                    properties=properties
                )
            )
    return search_results

@app.get("/schema_summary")
def get_schema_summary() -> List[TableColumn]:
    conn = connect_to_db()

    sql_tables_query = f"SELECT table_name FROM information_schema.tables WHERE table_schema = '{NOME_DATABASE}'"
    
    results, _ = execute_query(conn, sql_tables_query)
    table_names = [row[0] for row in results]

    schema: List[TableColumn] = []
    for table_name in table_names:
        sql_columns_query = f"SELECT * FROM {table_name} LIMIT 0"
        _, column_names = execute_query(conn, sql_columns_query)
        for column_name in column_names:
            schema.append(
                TableColumn(
                    table_name=table_name,
                    table_column=column_name
                )
            )
    return schema

@app.post("/add")
def add(data_line_request: AddRowRequest) -> AddRowResponse:
    data_line = data_line_request.data_line

    if not check_data_line_format(data_line):
        raise HTTPException(status_code=422, detail="Formato riga da inserire invalido")
    
    conn = connect_to_db()
    cursor = conn.cursor()

    data_to_insert = data_line.split(",")
    for i in range(len(data_to_insert)):
        data_to_insert[i] = data_to_insert[i].strip()
    data_to_insert = tuple(data_to_insert)

    """ Controllo se è presente una riga con la stessa occorrenza nella primary key """
    sql_check_query = f"SELECT * FROM movies WHERE titolo = '{data_to_insert[0]}'"
    results, _ = execute_query(conn, sql_check_query)

    if results == []:
        sql_command = f"INSERT INTO movies (titolo, regista, eta_autore, anno, genere, piattaforma_1, piattaforma_2) " \
                        f"VALUES ('{data_to_insert[0]}', '{data_to_insert[1]}', {data_to_insert[2]}, {data_to_insert[3]}, " \
                                f"'{data_to_insert[4]}', '{data_to_insert[5]}', '{data_to_insert[6]}')"
    else:
        sql_command = f"UPDATE movies " \
                        f"SET regista = '{data_to_insert[1]}', "\
                        f"eta_autore = {data_to_insert[2]}, "\
                        f"anno = {data_to_insert[3]}, "\
                        f"genere = '{data_to_insert[4]}', "\
                        f"piattaforma_1 = '{data_to_insert[5]}', "\
                        f"piattaforma_2 = '{data_to_insert[6]}' " \
                        f"WHERE titolo = '{data_to_insert[0]}'"
    cursor.execute(sql_command)

    conn.commit()

    cursor.close()
    conn.close()

    return AddRowResponse(
        status="ok"
    )
    