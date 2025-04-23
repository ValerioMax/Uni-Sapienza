from fastapi import FastAPI, HTTPException, Request, Form
from fastapi.templating import Jinja2Templates
import requests

app = FastAPI()
templates = Jinja2Templates(directory="../../templates") # "../../templates" percorso runnando questo programma da dentro la cartella server/

# URL del server a cui connettersi
API_BASE_URL = "http://127.0.0.1:8000"

@app.get("/")
def index(request: Request):
    try:
        response = requests.get(f"{API_BASE_URL}/inventory")
        response.raise_for_status()
        data = response.json()
    except requests.RequestException as e:
        data = []
        print("Errore nella chiamata a API: ", e)

    print(data)
    context = {"request": request, "items": data}
    return templates.TemplateResponse("index.html", context)

# quando si submitta il form cliccando il bottone l'azione è andare su questo URL che chiama questa funzione
@app.post("/buy")
def buy(request: Request,
        username: str = Form(default=...),
        password: str = Form(default=...),
        item_name: str = Form(default=...),
        quantity: int = Form(default=...)):
    
    payload = {
        "username": username,
        "password": password,
        "item_name": item_name,
        "quantity": quantity
    }
    try:
        response = requests.post(f"{API_BASE_URL}/purchase", json=payload)
        response.raise_for_status()
        data = response.json()
    except requests.RequestException as e:
        data = None
        print("Errore nella chiamata a API: ", e)

    context = {"request": request, "esito": data}
    return templates.TemplateResponse("index.html", context)



if __name__ == "__main__":
    import uvicorn
    # URL su cui si runna questo server 
    # (runno su porta diversa perchè devo simulare due macchine diverse
    # --> una per api_server e altra per html_server (server intermedio))
    uvicorn.run(app, host="127.0.0.1", port=8007)