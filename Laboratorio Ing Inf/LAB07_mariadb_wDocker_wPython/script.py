import mariadb

def execute_query(connection: mariadb.Connection, query: str):
    cursor: mariadb.Cursor = connection.cursor()
    cursor.execute(query)

    results = cursor.fetchall()
    connection.commit()

    cursor.close()
    return results

conn = mariadb.connect(
    host="127.0.0.1",
    port=3304,
    user="root",
    password="rootpassword",
    database="prova_db"
)

query = "SELECT * " \
        "FROM users"

result = execute_query(conn, query)
print(result, '\n')

# NOTA: lascia uno spazio se vai a capo se no lo prende come "SELECT emailFROM usersWHERE ..."
query = "SELECT email " \
        "FROM users " \
        "WHERE name = 'Alice Rossi'"

result = execute_query(conn, query)
print(result, '\n')

conn.close()