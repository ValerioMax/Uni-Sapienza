from e_store.store.store import Store
from e_store.customer.promotional_customer import PromotionalCustomer
from e_store.store_item.normal_item import NormalItem
from e_store.store_item.foreign_item import ForeignItem

def run_store() -> None:
    """Run the store simulation."""
    store = Store(1000)
    store.inventory.add_item(NormalItem("Laptop", 500), 5)
    store.inventory.add_item(ForeignItem("Smartphone", 800), 3)
    
    
    customer = PromotionalCustomer("Alice", 1000, "password123")
    if isinstance(customer, PromotionalCustomer):
        print("You are a promotional customer, you will get a discount!")
        
    while True:
        print(f"Your balance: {customer.balance}")
        print("Store Inventory:")
        for name, data in store.inventory.get_items().items():
            print(f"{name}: {data['quantity']} available at {data['item'].get_price()} each")
        
        choice = input("Enter item to buy or 'quit' to exit: ")
        if choice == "quit":
            break
        
        quantity = int(input("Enter quantity: "))
        
        if store.sell_item(customer, choice, quantity):
            print("Purchase successful!")
        else:
            print("Purchase failed!")
        
        print()
