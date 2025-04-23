class GenericItem:
    """Generic item class."""
    def __init__(self, name: str, price: float) -> None:
        self.name = name
        self.price = price
        
    def get_price(self) -> float:
        """Get the price of the item."""
        return self.price