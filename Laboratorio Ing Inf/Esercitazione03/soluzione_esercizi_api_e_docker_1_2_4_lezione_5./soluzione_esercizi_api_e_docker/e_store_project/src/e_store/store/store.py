from e_store.store_inventory.store_inventory import StoreInventory
from e_store.customer.generic_customer import GenericCustomer

class Store:
    """Store containing inventory and balance."""
    def __init__(self, balance: float) -> None:
        self.inventory = StoreInventory()
        self.balance = balance
    
    def sell_item(self, customer: GenericCustomer, item_name: str, quantity: int) -> bool:
        """Sell an item to a customer if possible."""
        if item_name in self.inventory.get_items():
            item_data = self.inventory.get_items()[item_name]
            total_price = item_data['item'].get_price() * quantity
            if customer.purchase(total_price) and self.inventory.remove_item(item_name, quantity):
                self.balance += total_price
                return True
        return False
