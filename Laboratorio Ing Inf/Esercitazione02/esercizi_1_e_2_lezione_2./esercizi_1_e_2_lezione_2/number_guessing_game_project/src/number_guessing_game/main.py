# main.py
from number_guessing_game.game.game import NumberGuessGame
from number_guessing_game.players.human_player import HumanPlayer
from number_guessing_game.players.cpu_player import CpuPlayer
from number_guessing_game.players.fast_cpu_player import FastCpuPlayer

if __name__ == "__main__":
    player_type = input("Choose player type: human, cpu, or fast_cpu: ").strip().lower()
    max_value = 10
    
    if player_type == "human":
        player = HumanPlayer("Human")
    elif player_type == "cpu":
        player = CpuPlayer("CPU")
    elif player_type == "fast_cpu":
        player = FastCpuPlayer("FastCPU", max_value)
    else:
        print("Invalid choice. Defaulting to CPU.")
        player = CpuPlayer("CPU")
    
    game = NumberGuessGame(player, max_value)
    game.play()
