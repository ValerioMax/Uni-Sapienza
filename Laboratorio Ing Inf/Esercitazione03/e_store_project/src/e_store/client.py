import requests
from requests.exceptions import HTTPError

BASE_URL = "http://127.0.0.1:8000"


def get_inventory() -> None:
    # faccio request a quell'URL, Server risponde e metto contenuto risposta in response
    response = requests.get(f"{BASE_URL}/inventory")
    data = response.json()
    for item in data:
        print(f"{item["name"]}, {item["quantity"]}, {item["price"]}")

def get_item_information(item_name) -> None:
    response = requests.get(f"{BASE_URL}/items/{item_name}")
    try:
        response.raise_for_status() # raise di eventuale HTTPError (es: 404)
        data = response.json()
        print(f"name: {data["name"]}, qt: {data["quantity"]}, price: ${data["price"]}")
    except HTTPError as http_error:
        error_status = http_error.response.status_code
        error_data = http_error.response.json()
        print(f"error: {error_status}\ndetail: {error_data["detail"]}")

def get_balance(username) -> float:
    # non mi conviene chiamare .json() su questa linea perché se arrivasse un'errore (es: 404)...
    response = requests.get(f"{BASE_URL}/users/{username}/balance")
    try:
        #...non potrei chiamare questa istr per raisare il giusto errore poi
        response.raise_for_status() # raise di eventuale HTTPError (es: 404)
        data = response.json()
        return data["balance"]
    except HTTPError as http_error:
        # per come viene gestito l'errore "status_error" non è preso come key della HTTPException e va preso così
        error_status = http_error.response.status_code
        error_data = http_error.response.json()
        print(f"error: {error_status}\ndetail: {error_data["detail"]}")
        return None

def make_purchase(username: str, password: str, item_name: str, quantity: int) -> None:
    payload = {
        "username": username,
        "password": password,
        "item_name": item_name,
        "quantity": quantity
    }
    response = requests.post(f"{BASE_URL}/purchase", json=payload)
    data = response.json()
    print(f"esito: {data["success"]}\nmessage: {data["message"]}")

get_inventory()
print()

balance = get_balance("Valerio")
print(f"user balance: {balance}\n")

balance = get_balance("pippuz")
print(f"user balance: {balance}\n")

get_item_information("mouse")
print()

get_item_information("caffè_utopia")
print()

make_purchase("pimp", "frozaroma", "mouse", 1)
print()

make_purchase("Valerio", "frozaroma", "mouse", 1)
print()

get_inventory()
print()

balance = get_balance("Valerio")
print(f"user balance: {balance}\n")
