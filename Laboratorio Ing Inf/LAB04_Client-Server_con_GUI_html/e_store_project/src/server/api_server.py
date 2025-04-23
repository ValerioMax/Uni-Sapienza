from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

from e_store.customer.generic_customer import GenericCustomer
from e_store.customer.promotional_customer import PromotionalCustomer
from e_store.store_item.generic_item import GenericItem
from e_store.store_inventory.store_inventory import StoreInventory
from e_store.store.store import Store

from typing import List, Dict, Optional

app = FastAPI(title="E-Store API")

registered_users: Dict[str, GenericCustomer] = {
    "Valerio": PromotionalCustomer("xxValeriusxx", "frozaroma", 9999),
    "Marius": GenericCustomer("mario", "1", 3)
}

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

class InventoryItem(BaseModel):
    name: str
    quantity: int
    price: float

class ItemInfo(BaseModel):
    name: str
    quantity: int
    price: float

class UserBalance(BaseModel):
    username: str
    balance: float

class Purchase(BaseModel):
    username: str
    password: str
    item_name: str
    quantity: int

class PurchaseResponse(BaseModel):
    success: bool
    message: str
    new_user_balance: Optional[float] = None # Optional[float] : di base è float, ma può anche non essere messo quando si definisce un oggetto di questo tipo e in questo caso campo viene settato a None

#self.items: Dict[str, List[List[GenericItem], int]] = {}

# Server handling functions quando arriva una request (GET or POST) dal Client
# all'URL specificato nel decorator.
# per le richieste GET i param della funzione corrispondono alle variabili fra {} nell'URL
# --> sono richieste dove Client RICHIEDE qualcosa dal server
# per le richieste POST i param della funzione sono quelli che vogliamo
# --> sono richieste dove Client MANDA qualcosa al server (richiesta del Client in questo caso ha un payload --> ovvero il parametro)

@app.get("/inventory")
def get_inventory() -> List[InventoryItem]:
    items: List[InventoryItem] = []
    for item_name in store.inventory.items:
        items.append(
            InventoryItem(
                name=item_name,
                quantity=store.inventory.items[item_name][1],
                price=store.inventory.items[item_name][0][0].price
            )
        )
    return items # oggetto mandato al Client in risposta alla sua richiesta GET

@app.get("/users/{username}/items")
def get_user_items(username):
    pass

@app.get("/items/{item_name}")
def get_item_information(item_name) -> ItemInfo:
    if item_name not in store.inventory.items:
        raise HTTPException(
            status_code=404,
            detail=f"Item {item_name} non trovato!"
        )
    return ItemInfo(
        name=item_name,
        quantity=store.inventory.items[item_name][1],
        price=store.inventory.items[item_name][0][0].price
    )

@app.get("/users/{username}/balance")
def get_balance(username) -> UserBalance:
    if username not in registered_users:
        raise HTTPException(
            status_code=404,
            detail=f"User {username} non trovato!"
        )
    customer = registered_users[username]
    return UserBalance(
        username=username,
        balance=customer.balance
    )

@app.post("/purchase")
def purchase(purchase: Purchase) -> PurchaseResponse:
    username = purchase.username
    password = purchase.password
    item_name = purchase.item_name
    quantity = purchase.quantity

    if (username not in registered_users or
        registered_users[username].password != password):
        return PurchaseResponse(
            success=False,
            message=f"user {username} non esiste o credenziali sbagliate"
        )
    
    customer = registered_users[username]
    
    if item_name not in store.inventory.items:
        return PurchaseResponse(
            success=False,
            message=f"item {item_name} non esiste nell'inventory dello store"
        )
    
    if store.inventory.items[item_name][1] < quantity:
        return PurchaseResponse(
            success=False,
            message=f"non ci sono abbastanza item {item_name} nell'inventory dello store"
        )
    
    item_to_buy = store.inventory.get_item(item_name)
    total_price = item_to_buy.price * quantity

    if total_price > customer.balance:
        return PurchaseResponse(
            success=False,
            message=f"non hai abbastanza soldi per comprare x{quantity} {item_name}"
        )
    
    money_gained = customer.send_money(total_price)
    for i in range(quantity):
        store.inventory.remove_item(item_name)
    store.balance += money_gained

    return PurchaseResponse(
            success=True,
            message=f"Acquisto di item {username} effettuato con successo!"
        )

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)