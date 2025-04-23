from typing import Any, Dict
from e_store.store_item.generic_item import GenericItem

class StoreInventory:
    """Handles store inventory management."""
    def __init__(self) -> None:
        # The inventory holds item names as keys, and values are dicts with 'item' and 'quantity'
        self.items: Dict[str, Dict[str, Any]] = {}
    
    def add_item(self, item: GenericItem, quantity: int) -> None:
        """Add an item to inventory."""
        self.items[item.name] = {'item': item, 'quantity': quantity}
    
    def remove_item(self, item_name: str, quantity: int) -> bool:
        """Remove an item from inventory if quantity is sufficient."""
        if item_name in self.items and self.items[item_name]['quantity'] >= quantity:
            self.items[item_name]['quantity'] -= quantity
            return True
        return False
    
    def get_items(self) -> Dict[str, Dict[str, Any]]:
        """Return current inventory."""
        return self.items
