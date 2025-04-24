import requests
from fastapi import FastAPI, HTTPException

app = FastAPI()

SERVICE_A_URL = "http://service_a:8000/"

@app.get("/")
def call_service_a():
    try:
        response = requests.get(SERVICE_A_URL)
        response.raise_for_status()
    except requests.RequestException as e:
        raise HTTPException(
            status_code=500,
            detail=f"Errore nella comunicazione con service_a: {e}")
    data = response.json()
    return {"message": "service_b response (called from service_a)",
            "data_from_service_a": data}