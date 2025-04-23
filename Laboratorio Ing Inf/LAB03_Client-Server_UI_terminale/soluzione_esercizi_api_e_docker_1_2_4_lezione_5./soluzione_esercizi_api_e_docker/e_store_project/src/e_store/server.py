from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import Dict, Optional, List
from e_store.store.store import Store
from e_store.customer.promotional_customer import PromotionalCustomer
from e_store.store_item.normal_item import NormalItem
from e_store.store_item.foreign_item import ForeignItem
from e_store.customer.generic_customer import GenericCustomer

app = FastAPI(title="E-Store API")

store = Store(1000)
store.inventory.add_item(NormalItem("Laptop", 500), 5)
store.inventory.add_item(ForeignItem("Smartphone", 800), 3)

users: Dict[str, GenericCustomer] = {
    "Alice": PromotionalCustomer("Alice", 1000, "123"),
    "Bob": PromotionalCustomer("Bob", 800, "123"),
}

class InventoryItem(BaseModel):
    name: str
    quantity: int
    price: float

class UserItem(BaseModel):
    name: str
    quantity: int

class ItemInfo(BaseModel):
    name: str
    quantity: int
    price: float

class UserBalance(BaseModel):
    username: str
    balance: float

class PurchaseRequest(BaseModel):
    username: str
    password: str
    item_name: str
    quantity: int

class PurchaseResponse(BaseModel):
    success: bool
    message: str
    new_balance: Optional[float] = None

@app.get("/inventory")
def get_inventory() -> List[InventoryItem]:
    inventory_items: List[InventoryItem] = []
    for name, data in store.inventory.get_items().items():
        inventory_items.append(
            InventoryItem(
                name=name,
                quantity=data["quantity"],
                price=data["item"].get_price()
            )
        )
    return inventory_items

@app.get("/user/{username}/items")
def get_user_items(username: str) -> List[UserItem]:
    if username not in users:
        raise HTTPException(status_code=404, detail=f"Utente {username} non trovato")
    customer = users[username]
    user_items: List[UserItem] = []
    for item_name, quantity in customer.items.items():
        user_items.append(
            UserItem(
                name=item_name,
                quantity=quantity
            )
        )
    return user_items

@app.get("/item/{item_name}")
def get_item_information(item_name: str) -> ItemInfo:
    inventory = store.inventory.get_items()
    if item_name not in inventory:
        raise HTTPException(status_code=404, detail=f"Item {item_name} non trovato")
    item_data = inventory[item_name]
    return ItemInfo(
        name=item_name,
        quantity=item_data["quantity"],
        price=item_data["item"].get_price()
    )

@app.get("/user/{username}/balance")
def get_balance(username: str) -> UserBalance:
    if username not in users:
        raise HTTPException(status_code=404, detail=f"Utente {username} non trovato")
    customer = users[username]
    return UserBalance(
        username=username,
        balance=customer.balance
    )

@app.post("/purchase")
def purchase(purchase_req: PurchaseRequest) -> PurchaseResponse:
    username: str = purchase_req.username
    password: str = purchase_req.password

    if username not in users or users[username].password != password:
        return PurchaseResponse(
            success=False,
            message="Username o password non validi"
        )

    customer: GenericCustomer = users[username]
    item_name: str = purchase_req.item_name
    quantity: int = purchase_req.quantity
    inventory: Dict = store.inventory.get_items()

    if item_name not in inventory:
        return PurchaseResponse(
            success=False,
            message=f"Item {item_name} non disponibile nel negozio"
        )

    available_quantity: int = inventory[item_name]["quantity"]
    if quantity > available_quantity:
        return PurchaseResponse(
            success=False,
            message=f"Quantità richiesta ({quantity}) maggiore della disponibilità ({available_quantity})"
        )

    item_price: float = inventory[item_name]["item"].get_price()
    total_cost: float = item_price * quantity
    if customer.balance < total_cost:
        return PurchaseResponse(
            success=False,
            message=f"Saldo insufficiente: hai {customer.balance}, necessari {total_cost}"
        )

    if store.sell_item(customer, item_name, quantity):
        if item_name in customer.items:
            customer.items[item_name] += quantity
        else:
            customer.items[item_name] = quantity
        return PurchaseResponse(
            success=True,
            message=f"Acquisto di {quantity} {item_name} completato con successo",
            new_balance=customer.balance
        )
    else:
        return PurchaseResponse(
            success=False,
            message="Acquisto fallito per un errore interno"
        )

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
