from e_store.customer.generic_customer import GenericCustomer

class PromotionalCustomer(GenericCustomer):
    """Promotional customer with discount."""
    def __init__(self, name: str, balance: float, password: str) -> None:
        super().__init__(name, balance, password)
        self.discount = 0.1  # 10% di sconto
    
    def purchase(self, price: float) -> bool:
        """Try to purchase an item at the given price with discount."""
        discounted_price = price * (1 - self.discount)
        return super().purchase(discounted_price)