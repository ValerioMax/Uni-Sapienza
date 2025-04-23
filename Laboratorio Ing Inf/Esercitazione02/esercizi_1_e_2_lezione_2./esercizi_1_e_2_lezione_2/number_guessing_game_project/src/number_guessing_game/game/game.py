import random
import datetime
import csv
import os

from number_guessing_game.players.player import Player

class NumberGuessGame:
    """Game logic for Number Guess."""
    def __init__(self, player: Player, max_number: int) -> None:
        self.player = player
        self.target = random.randint(0, max_number)
        self.attempts = []
        self.max_number = max_number
    
    def play(self) -> None:
        print(f"{self.player.name}, try to guess the number between 0 and {self.max_number}!")
        attempts_count = 0
        while True:
            guess = self.player.make_guess()
            self.attempts.append(guess)
            attempts_count += 1
            
            if guess < self.target:
                feedback = "too low"
            elif guess > self.target:
                feedback = "too high"
            else:
                feedback = "correct"
            
            self.player.receive_feedback(feedback)
            
            if feedback == "correct":
                self.save_results()
                print(f"Congratulations {self.player.name}! You guessed it in {attempts_count} attempts.")
                break
    
    def save_results(self) -> None:
        # Get the current script's directory
        script_dir = os.path.dirname(os.path.abspath(__file__))
        source_dir = os.path.dirname(os.path.dirname(script_dir))
        outside_dir = os.path.dirname(source_dir)
        data_dir = os.path.join(outside_dir, "data")
        
        # Create the "data" directory if it doesn't exist
        os.makedirs(data_dir, exist_ok=True)
        
        # Define the file path in the "data" folder
        file_path = os.path.join(data_dir, "results.tsv")
        
        # Write the results to the file
        current_datetime = datetime.datetime.now()

        # Format separately for date and time
        date = current_datetime.strftime("%Y-%m-%d")
        time = current_datetime.strftime("%H:%M:%S")
        with open(file_path, "a", newline="") as file:
            writer = csv.writer(file, delimiter='\t')
            writer.writerow([self.player.name, self.target, len(self.attempts), self.attempts, date, time])
        print(f"Log of this game has been appended to: {file_path}")