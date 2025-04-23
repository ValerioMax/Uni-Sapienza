from number_guessing_game.players.player import Player


class HumanPlayer(Player):
    """Human player with terminal input/output."""
    def make_guess(self) -> int:
        while True:
            try:
                return int(input(f"{self.name}, enter your guess: "))
            except ValueError:
                print("Invalid input, please enter a number.")
    
    def receive_feedback(self, feedback: str) -> None:
        print(feedback)
