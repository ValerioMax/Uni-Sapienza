from e_store.customer.generic_customer import GenericCustomer
from e_store.customer.normal_customer import NormalCustomer
from e_store.customer.promotional_customer import PromotionalCustomer
from e_store.store.store import Store
from e_store.store_inventory.store_inventory import StoreInventory
from e_store.store_item.generic_item import GenericItem

def run_store():
    username = input("Inserisci username: ")
    password = input("Inserisci password: ")
    user_type = input("Inserisci tipo di user: normal[0], promotional[1]: ")
    starting_balance = 300

    item1 = GenericItem("mouse", 10)
    item2 = GenericItem("laptop", 150)

    inventory = StoreInventory()

    inventory.add_item(item1)
    inventory.add_item(item1)
    inventory.add_item(item1)
    inventory.add_item(item1)

    inventory.add_item(item2)
    inventory.add_item(item2)

    store = Store(inventory, 0)

    if user_type == 0:
        user = NormalCustomer(username, password, starting_balance)
    elif user_type == 1:
        user = PromotionalCustomer(username, password, starting_balance)
    else:
        user = GenericCustomer(username, password, starting_balance)

    while(1):
        print("Oggetti a dispozione:")
        store.list_items()
        item_name = input("Inserisci nome oggetto che vuoi comprare: ")
        if (item_name == "quit"):
            break
        store.purchase(item_name, user)
        print(store)
        print(f"user balance: ${user.balance}")
        print()