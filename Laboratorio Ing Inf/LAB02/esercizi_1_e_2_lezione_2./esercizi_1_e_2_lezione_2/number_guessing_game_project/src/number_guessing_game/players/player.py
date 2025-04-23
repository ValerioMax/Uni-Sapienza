from abc import ABC, abstractmethod

class Player(ABC):
    """Abstract player class."""
    def __init__(self, name: str) -> None:
        self.name = name
    
    @abstractmethod
    def make_guess(self) -> int:
        pass
    
    @abstractmethod
    def receive_feedback(self, feedback: str) -> None:
        pass
