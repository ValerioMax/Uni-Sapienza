from urllib.parse import quote
from fastapi import FastAPI, HTTPException, Request, Form
from fastapi.templating import Jinja2Templates
from fastapi.staticfiles import StaticFiles
import requests

# Creazione dell'applicazione web
app = FastAPI()

# Collegamento della cartella di template e di stili all'app
templates = Jinja2Templates(directory="./templates")
app.mount("/styles", StaticFiles(directory="./styles"), name="styles")

# URL del server a cui connettersi
API_BASE_URL = "http://backend:8003"

@app.get("/")
def index(request: Request):
    """ endpoint GET per la home page  """

    context = {"request": request}
    return templates.TemplateResponse("index.html", context)

@app.get("/query")
def get_query_output(request: Request):
    """ endpoint GET per l'inserimento della query in linguaggio naturale """

    query = request.query_params.get("query_input")
    try:
        response = requests.get(f"{API_BASE_URL}/search/{quote(query)}")
        response.raise_for_status()
        data = response.json()
        context = {"request": request, "query_output": data}
    except requests.RequestException as e:
        error_detail = e.response.json().get("detail")
        context = {"request": request, "error": response.status_code, "error_detail": error_detail}
    return templates.TemplateResponse("query_output.html", context)

@app.get("/schema")
def get_schema_summary(request: Request):
    """ endpoint GET per ottenere il riassunto dello schema logico del database """

    try:
        response = requests.get(f"{API_BASE_URL}/schema_summary")
        response.raise_for_status()
        data = response.json()
        context = {"request": request, "schema": data}
    except requests.RequestException as e:
        context = {"request": request, "error": response.status_code, "error_detail": "errore"}
    return templates.TemplateResponse("schema_summary.html", context)

@app.post("/add_data")
def add_data(request: Request, data_line: str = Form(default=...)):
    """ endpoint POST per l'inserimento/update di una riga nella tabella movies del database """
    
    payload = {"data_line": data_line}

    try:
        response = requests.post(f"{API_BASE_URL}/add", json=payload)
        response.raise_for_status()
        data = response.json()
        context = {"request": request, "data": data, "data_line": data_line}
    except requests.RequestException as e:
        error_detail = e.response.json().get("detail")
        context = {"request": request, "error": response.status_code, "error_detail": error_detail}

    return templates.TemplateResponse("row_insert.html", context)
