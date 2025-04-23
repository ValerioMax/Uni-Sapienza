import random
import datetime
import csv
import os
from typing import List, Optional


class NumberGuessGame:
    """Game logic for Number Guess Game"""

    def __init__(self, player_name: str, max_number: int) -> None:
        self.player_name = player_name
        self.target = random.randint(0, max_number)
        self.attempts: List[int] = []
        self.max_number = max_number
        self.is_over = False

    def play_turn(self, guess: int) -> str:
        """Make a guess and return feedback ('too low', 'too high', 'correct')."""
        if self.is_over:
            raise ValueError("Game is already over.")

        self.attempts.append(guess)

        if guess < self.target:
            return "too low"
        elif guess > self.target:
            return "too high"
        else:
            self.is_over = True
            return "correct"

    def get_attempts(self) -> List[int]:
        """Return all guesses made so far."""
        return self.attempts

    def is_finished(self) -> bool:
        """Return whether the game has been completed."""
        return self.is_over

    def get_target(self) -> Optional[int]:
        """Return the target number (only if game is over)."""
        return self.target if self.is_over else None

    def get_player_name(self) -> str:
        """Return the player's name."""
        return self.player_name


def main():
    print("Welcome to the Number Guess Game!")

    # Get player name and max number
    player_name = input("Enter your name: ").strip()
    while not player_name:
        player_name = input("Please enter a valid name: ").strip()

    max_number = 100

    # Start game
    game = NumberGuessGame(player_name, max_number)
    print(f"\nHi {player_name}, I'm thinking of a number between 0 and {max_number}. Can you guess it?")

    while not game.is_finished():
        try:
            guess = int(input("Your guess: "))
            feedback = game.play_turn(guess)
            print(f"That is {feedback}.")
        except ValueError as ve:
            print(f"Error: {ve}")
        except Exception as e:
            print(f"Unexpected error: {e}")

    # Game over
    print(f"\nCongratulations, {player_name}! You guessed the number {game.get_target()} in {len(game.get_attempts())} attempts.")

if __name__ == "__main__":
    main()
