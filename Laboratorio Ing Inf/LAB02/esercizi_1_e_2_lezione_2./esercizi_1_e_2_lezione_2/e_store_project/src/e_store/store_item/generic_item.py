class GenericItem:
    """Represents an item with a price."""
    def __init__(self, name: str, price: float) -> None:
        self.name = name
        self.price = price
    
    def get_price(self) -> float:
        """Return item price."""
        return self.price
