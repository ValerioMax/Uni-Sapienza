from urllib.parse import quote
from fastapi import FastAPI, HTTPException, Request, Form
from fastapi.templating import Jinja2Templates
from fastapi.staticfiles import StaticFiles
import requests

app = FastAPI()
#templates = Jinja2Templates(directory="../../templates") # "../../templates" percorso runnando questo programma da dentro la cartella server/
templates = Jinja2Templates(directory="./templates")
app.mount("/styles", StaticFiles(directory="./styles"), name="styles")

# URL del server a cui connettersi
API_BASE_URL = "http://backend:8003"

@app.get("/")
def index(request: Request):
    context = {"request": request}
    return templates.TemplateResponse("index.html", context)

@app.get("/query")
def get_query_output(request: Request):
    query = request.query_params.get("query_input")
    if query:
        try:
            response = requests.get(f"{API_BASE_URL}/search/{quote(query)}")
            response.raise_for_status()
            data = response.json()
            context = {"request": request, "query_output": data}
        except requests.RequestException as e:
            error_detail = e.response.json().get("detail")
            context = {"request": request, "error": response.status_code, "error_detail": error_detail}
    else:
        context = {"request": request, "error": "Inserisci una query!"}
    return templates.TemplateResponse("query_output.html", context)

@app.get("/schema")
def get_schema_summary(request: Request):
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
    payload = {"data_line": data_line}
    if payload:
        try:
            response = requests.post(f"{API_BASE_URL}/add", json=payload)
            response.raise_for_status()
            data = response.json()
            context = {"request": request, "data": data, "data_line": data_line}
        except requests.RequestException as e:
            error_detail = e.response.json().get("detail")
            context = {"request": request, "error": response.status_code, "error_detail": error_detail}
    else:
        context = {"request": request, "error": "Inserisci una riga da inserire nel database!"}
    return templates.TemplateResponse("row_insert.html", context)
