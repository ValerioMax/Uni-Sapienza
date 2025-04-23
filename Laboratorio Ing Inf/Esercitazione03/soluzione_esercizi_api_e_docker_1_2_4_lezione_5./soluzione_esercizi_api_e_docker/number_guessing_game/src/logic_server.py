from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import Dict, Optional, List
from game_logic import NumberGuessGame

app = FastAPI(title="Number Guess Game API")

# In-memory store for games (player_name -> NumberGuessGame instance)
games: Dict[str, NumberGuessGame] = {}

# Pydantic models
class StartGameRequest(BaseModel):
    player_name: str
    max_number: int = 100

class GuessRequest(BaseModel):
    player_name: str
    guess: int

class GuessResponse(BaseModel):
    result: str
    attempts: List[int]
    finished: bool
    target: Optional[int] = None

class GameStatusResponse(BaseModel):
    attempts: List[int]
    finished: bool
    target: Optional[int]

@app.post("/start")
def start_game(request: StartGameRequest):
    if request.player_name in games and not games[request.player_name].is_finished():
        raise HTTPException(status_code=400, detail="Game already in progress for this player.")

    game = NumberGuessGame(request.player_name, request.max_number)
    games[request.player_name] = game
    return {"message": f"Game started for {request.player_name} with max number {request.max_number}."}

@app.post("/guess")
def make_guess(request: GuessRequest) -> GuessResponse:
    game = games.get(request.player_name)
    if not game:
        raise HTTPException(status_code=404, detail="No game found for this player.")
    if game.is_finished():
        raise HTTPException(status_code=400, detail="Game already finished.")

    try:
        result = game.play_turn(request.guess)
    except ValueError as e:
        raise HTTPException(status_code=400, detail=str(e))

    response = GuessResponse(
        result=result,
        attempts=game.get_attempts(),
        finished=game.is_finished(),
        target=game.get_target() if game.is_finished() else None
    )


    return response

@app.get("/status/{player_name}")
def game_status(player_name: str) -> GameStatusResponse:
    game = games.get(player_name)
    if not game:
        raise HTTPException(status_code=404, detail="No game found for this player.")

    return GameStatusResponse(
        attempts=game.get_attempts(),
        finished=game.is_finished(),
        target=game.get_target() if game.is_finished() else None
    )
