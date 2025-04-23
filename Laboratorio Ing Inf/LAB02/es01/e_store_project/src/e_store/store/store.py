from e_store.store_inventory.store_inventory import StoreInventory
from e_store.customer.generic_customer import GenericCustomer
from e_store.customer.promotional_customer import PromotionalCustomer
from e_store.customer.normal_customer import NormalCustomer

class Store:
    def __init__(self, inventory: StoreInventory, balance):
        self.inventory = inventory
        self.balance = balance

    def __str__(self):
        return f"store balance: {self.balance}"
    
    def list_items(self):
        self.inventory.list_items()

    def purchase(self, item_name: str, customer: GenericCustomer):
        item_to_buy = self.inventory.get_item(item_name)
        if not item_to_buy:
            return
        if item_to_buy.price > customer.balance:
            print("Not enough money!")
            return
        money_gained = customer.send_money(item_to_buy.price)
        self.inventory.remove_item(item_name)
        self.balance += money_gained
