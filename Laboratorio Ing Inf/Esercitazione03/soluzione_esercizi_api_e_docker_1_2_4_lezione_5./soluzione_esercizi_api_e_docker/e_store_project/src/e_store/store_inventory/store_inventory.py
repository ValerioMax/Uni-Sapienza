from typing import Dict, Any
from e_store.store_item.generic_item import GenericItem

class StoreInventory:
    """Store inventory class to manage items."""
    def __init__(self) -> None:
        self.inventory: Dict[str, Dict[str, Any]] = {}
    
    def add_item(self, item: GenericItem, quantity: int) -> None:
        """Add an item to the inventory."""
        item_name = item.name
        if item_name in self.inventory:
            self.inventory[item_name]["quantity"] += quantity
        else:
            self.inventory[item_name] = {"item": item, "quantity": quantity}
    
    def remove_item(self, item_name: str, quantity: int) -> bool:
        """Remove a certain quantity of an item from the inventory if possible."""
        if item_name in self.inventory and self.inventory[item_name]["quantity"] >= quantity:
            self.inventory[item_name]["quantity"] -= quantity
            # Se la quantità diventa zero, rimuoviamo l'item dall'inventario
            if self.inventory[item_name]["quantity"] == 0:
                del self.inventory[item_name]
            return True
        return False
    
    def get_items(self) -> Dict[str, Dict[str, Any]]:
        """Get all items in the inventory."""
        return self.inventory