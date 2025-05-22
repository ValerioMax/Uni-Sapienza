from fastapi import FastAPI, HTTPException, Request, Form
from fastapi.templating import Jinja2Templates
import requests

app = FastAPI()
#templates = Jinja2Templates(directory="../../templates") # "../../templates" percorso runnando questo programma da dentro la cartella server/

# URL del server a cui connettersi
#API_BASE_URL = "http://localhost:11434/api"
API_BASE_URL = "http://ollama:11434/api"

def pull_model(model):
    payload = { "model": model }
        
    try:
        response = requests.post(f"{API_BASE_URL}/pull", json=payload)
        response.raise_for_status()
        data = response.json()
        print(response, '\n\n', data)
    except requests.RequestException as e:
        data = None
        print("Errore nella chiamata a API per fare pull del modello: ", e)

@app.get("/")
def root(request: Request):
    return "sei nella root"

@app.get("/ask")
def ask(request: Request):
    
    # se il modello non 
    pull_model("gemma3:1b")
    
    # then make question
    question = "Is Rome the capital of Italy? (answer only Yes or No)"
    question = "quanti ani ha vittorio cava?"
    payload = {
        "model": "gemma3:1b",
        "messages": [
            {"role": "user", "content": question}
        ],
        "stream": False
    }

    try:
        response = requests.post(f"{API_BASE_URL}/chat", json=payload)
        response.raise_for_status()
        data = response.json()
        print(response, '\n\n', data)
    except requests.RequestException as e:
        data = None
        print("Errore nella chiamata a API per rispondere alla query: ", e)

    #output = data["message"]["content"]

    return data

