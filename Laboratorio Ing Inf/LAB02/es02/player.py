from abc import ABC, abstractmethod
import random
from datetime import datetime

class Player(ABC):
    attempts = 0

    def __init__(self, name): # metodo non usato direttamente (non si può istanziare direttamente una classe astratta)
        self.name = name                # ma chiamato dalle classi figlie

    @abstractmethod
    def start_playing(self, max_num):
        pass
    
    def store_results(self, path, num):
        print("Storing results into results.tsv")

        with open(path, 'a') as file:
            file.write(f"{self.name}\t")
            file.write(f"{num}\t")
            file.write(f"{self.attempts}\t")
            file.write(f"{datetime.now()}\n")

        print("Operation ended")

class HumanPlayer(Player):
    def __init__(self, name):
        super().__init__(name)
    
    def start_playing(self, max_num):
        print(f"{self.name} now playing")
        self.attempts = 0
        num = random.randint(0, max_num)
        flag = False

        while (not flag):
            try:
                guess = int(input("Make a guess: "))
            except:
                print("Inserisci un numero")
            self.attempts += 1

            if (guess > num):
                print("Troppo alto")
            elif (guess < num):
                print("Troppo basso")
            else:
                print("Indovinato!")
                self.store_results("results.tsv", num)
                flag = True

class CpuPlayer(Player):
    def __init__(self, name):
        super().__init__(name)

    def start_playing(self, max_num):
        print(f"{self.name} now playing")
        self.attempts = 0
        num = random.randint(0, max_num)
        flag = False

        while (not flag):
            guess = random.randint(0, max_num)
            self.attempts += 1

            if (guess > num):
                print("Troppo alto")
            elif (guess < num):
                print("Troppo basso")
            else:
                print("Indovinato!")
                self.store_results("results.tsv", num)
                flag = True

class FastCpuPlayer(CpuPlayer):
    def __init__(self, name):
        super().__init__(name)

    def start_playing(self, max_num):
        print(f"{self.name} now playing")
        self.attempts = 0
        num = random.randint(0, max_num)
        flag = False
        
        min = 0
        max = max_num

        while (not flag):
            mid = min + (max - min) // 2
            self.attempts += 1

            if (mid == num):
                print("Indovinato!")
                self.store_results("results.tsv", num)
                flag = True
            elif (num < mid):
                print("Troppo alto")
                max = max - (max - min) // 2
            elif (num > mid):
                print("Troppo basso")
                min = min + (max - min) // 2
                
