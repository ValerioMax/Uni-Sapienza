from typing import Any, Dict, List
from e_store.store_item.generic_item import GenericItem

class StoreInventory:
    def __init__(self):
        # Dizionario chiave-valore es:
        #   {"laptop":[[laptop1, laptop2, laptop3], 3]
        #    "mouse": [[mouse1, mouse2], 2]}         
        self.items: Dict[str, List[List[GenericItem], int]] = {}
        self.num_items = 0
    
    def get_item(self, item_name):
        if item_name in self.items and self.items[item_name][1] > 0:
            return self.items[item_name][0][0]
        return None
    
    def add_item(self, item: GenericItem):
        if item.name in self.items:
            self.items[item.name][0].append(item)
            self.items[item.name][1] += 1
        else:
            self.items[item.name] = [[item], 1]
        self.num_items += 1
    
    def remove_item(self, item_name):
        if item_name in self.items and self.items[item_name][1] > 0:
            item_to_remove = self.items[item_name][0].pop()
            self.items[item_name][1] -= 1
            self.num_items -= 1
            return item_to_remove.price
        else:
            return 0
    
    def list_items(self):
        for item_name in self.items:
            if self.items[item_name][1] > 0:
                print(f"{item_name} -> qt: {self.items[item_name][1]}, price: ${self.items[item_name][0][0].price}")

        