#from fastapi import FastAPI, HTTPException, Request, Form
#from fastapi.templating import Jinja2Templates
import requests

#app = FastAPI()

# URL del server a cui connettersi
API_BASE_URL = "http://localhost:11434/api"

# firstly pull the model, if it is already pulled it does nothing
payload = { "model": "gemma3:1b" }

try:
    response = requests.post(f"{API_BASE_URL}/pull", json=payload)
    response.raise_for_status()
    data = response.json()
    print(response, '\n\n', data["message"]["content"])
except requests.RequestException as e:
    data = None
    print("Errore nella chiamata a API: ", e)


# then make question
question = "Is Rome the capital of Italy? (answer only Yes or No)"
question = "does a hand has fingers?"

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
    print(response, '\n\n', data["message"]["content"])
except requests.RequestException as e:
    data = None
    print("Errore nella chiamata a API: ", e)