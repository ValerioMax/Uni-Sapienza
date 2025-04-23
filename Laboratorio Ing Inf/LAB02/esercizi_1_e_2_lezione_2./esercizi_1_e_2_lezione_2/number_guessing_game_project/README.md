# Number Guessing Game Project

This project implements a simple number guessing game where the user or an AI guesses a number between 0 and a specified maximum value. The game supports three types of players: Human, CPU, and Fast CPU.

## Setting Up the Python Path

Before running the game, make sure to set the `PYTHONPATH` to the `src` directory. This ensures that Python can find and import the modules correctly.

1. Open a terminal.
2. Navigate to the project directory at the same level of the `src` folder.

For example:

```bash
cd /mnt/data/riccardo/laboratorio_di_programmazione/lezioni/lezione_2/esercizi_1_e_2_lezione_2/number_guessing_game_project
```

3. Set the `PYTHONPATH` environment variable:

```bash
export PYTHONPATH=$(pwd)/src
```

4. Now you can run the game by executing:

```bash
python3 src/number_guessing_game/main.py
```