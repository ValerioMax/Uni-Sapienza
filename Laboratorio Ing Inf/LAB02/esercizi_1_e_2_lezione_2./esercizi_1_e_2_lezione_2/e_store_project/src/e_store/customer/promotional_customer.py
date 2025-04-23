from e_store.customer.generic_customer import GenericCustomer

class PromotionalCustomer(GenericCustomer):
    """Customer with a 5% discount on purchases."""
    def purchase(self, price: float) -> bool:
        return super().purchase(price * 0.95)
