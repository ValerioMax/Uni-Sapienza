from typing import Dict

class GenericCustomer:
    """Generic customer class."""
    def __init__(self, name: str, balance: float, password: str) -> None:
        self.name = name
        self.balance = balance
        self.password = password
        self.items: Dict[str, int] = {}  # Dizionario che contiene il nome dell'item e la quantità
    
    def purchase(self, price: float) -> bool:
        """Try to purchase an item at the given price."""
        if self.balance >= price:
            self.balance -= price
            return True
        return False
    
    def add_item(self, item_name: str, quantity: int) -> None:
        """Add item to customer's inventory."""
        if item_name in self.items:
            self.items[item_name] += quantity
        else:
            self.items[item_name] = quantity