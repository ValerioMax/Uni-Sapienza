class GenericCustomer:
    """Represents a customer with balance and password."""
    def __init__(self, name: str, balance: float, password: str) -> None:
        self.name = name
        self.balance = balance
        # Please keep in mind that storing a password in a production system requires care
        # this is just a toy example. 
        self.password = password
    
    def can_afford(self, price: float) -> bool:
        """Check if the customer can afford an item."""
        return self.balance >= price

    def purchase(self, price: float) -> bool:
        """Deduct price from balance if affordable."""
        password_input = input("Enter the customer password: ")
        if password_input != self.password:
            print("Invalid password!")
            return False
        if self.can_afford(price):
            self.balance -= price
            return True
        return False
