from number_guessing_game.players.player import Player


class FastCpuPlayer(Player):
    """CPU player using binary search to guess optimally."""
    def __init__(self, name: str, max_value: int) -> None:
        super().__init__(name)
        self.low = 0
        self.high = max_value
        self.current_guess = (self.low + self.high) // 2
    
    def make_guess(self) -> int:
        return self.current_guess
    
    def receive_feedback(self, feedback: str) -> None:
        if feedback == "too low":
            self.low = self.current_guess + 1
        elif feedback == "too high":
            self.high = self.current_guess - 1
        self.current_guess = (self.low + self.high) // 2
