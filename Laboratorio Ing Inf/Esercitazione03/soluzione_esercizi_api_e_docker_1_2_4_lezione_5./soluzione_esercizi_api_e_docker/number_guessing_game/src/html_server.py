import os
from fastapi import FastAPI, Request, Form, HTTPException
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates
import requests

app = FastAPI(title="Number Guess Game HTML Interface")
templates = Jinja2Templates(directory="templates")

# URL of the API server (adjust if needed)
API_URL = os.getenv("LOGIC_API_URL", "http://localhost:8001")

@app.get("/", response_class=HTMLResponse)
def index(request: Request):
    """Home page to start a new game."""
    return templates.TemplateResponse("index.html", {"request": request})

@app.post("/start", response_class=HTMLResponse)
def start_game(
    request: Request,
    player_name: str = Form(...),
    max_number: int = Form(...)
):
    # Check if player_name or max_number is missing
    if not player_name or not max_number:
        error = "Player name and max number are required."
        return templates.TemplateResponse("index.html", {"request": request, "error": error})
    
    # Prepare JSON payload for the logic server
    data = {
        "player_name": player_name,
        "max_number": max_number
    }
    
    # Make a POST request to the logic server
    api_response = requests.post(f"{API_URL}/start", json=data)
    api_response.raise_for_status()  # This will raise an HTTPError for bad responses
    
    # If successful, return the game interface page
    return templates.TemplateResponse(
        "game.html",
        {"request": request, "player_name": player_name, "attempts": []}
    )

@app.post("/guess", response_class=HTMLResponse)
def make_guess(request: Request, player_name: str = Form(...), guess: int = Form(...)):
    """Submits a guess to the API endpoint."""
    data = {"player_name": player_name, "guess": guess}
    
    # Make a POST request to the logic server
    api_response = requests.post(f"{API_URL}/guess", json=data)
    api_response.raise_for_status()

    result_data = api_response.json()
    return templates.TemplateResponse(
        "game.html",
        {
            "request": request,
            "player_name": player_name,
            "attempts": result_data.get("attempts", []),
            "message": result_data.get("result", ""),
            "finished": result_data.get("finished", False),
            "target": result_data.get("target"),
        }
    )
