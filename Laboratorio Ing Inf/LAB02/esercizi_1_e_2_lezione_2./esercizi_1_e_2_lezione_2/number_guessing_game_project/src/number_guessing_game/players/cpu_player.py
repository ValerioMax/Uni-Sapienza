# players/cpu_player.py
from number_guessing_game.players.player import Player


class CpuPlayer(Player):
    """CPU player that guesses sequentially with +1 or -1 adjustments."""
    def __init__(self, name: str) -> None:
        super().__init__(name)
        self.current_guess = 0
        self.last_feedback = None
    
    def make_guess(self) -> int:
        if self.last_feedback == "too low":
            self.current_guess += 1
        elif self.last_feedback == "too high":
            self.current_guess -= 1
        return self.current_guess
    
    def receive_feedback(self, feedback: str) -> None:
        self.last_feedback = feedback
