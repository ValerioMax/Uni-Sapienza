from urllib.parse import quote
from fastapi import FastAPI, HTTPException, Request, Form
from fastapi.templating import Jinja2Templates
import requests

app = FastAPI()
#templates = Jinja2Templates(directory="../../templates") # "../../templates" percorso runnando questo programma da dentro la cartella server/
templates = Jinja2Templates(directory="./templates")

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
            context = {"request": request, "error": "errore bro!"}
    else:
        context = {"request": request, "error": "No query provided vro!"}
    return templates.TemplateResponse("index.html", context)

@app.get("/schema")
def get_schema_summary(request: Request):
    try:
        response = requests.get(f"{API_BASE_URL}/schema_summary")
        response.raise_for_status()
        data = response.json()
        context = {"request": request, "schema": data}
    except requests.RequestException as e:
        context = {"request": request, "error": "errore bro!"}
    return templates.TemplateResponse("index.html", context)

@app.post("/add_data")
def add_data(request: Request, data: str = Form(default=...)):
    payload = {"data_line": data}

    try:
        response = requests.post(f"{API_BASE_URL}/add", json=payload)
        response.raise_for_status()
        data = response.json()
    except requests.RequestException as e:
        data = None
        print("Errore nella chiamata a API: ", e)

    context = {"request": request, "esito": data}
    return templates.TemplateResponse("index.html", context)

#if __name__ == "__main__":
#    import uvicorn
#    uvicorn.run(app, host="127.0.0.1", port=8007)