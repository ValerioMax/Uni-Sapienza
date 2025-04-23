from e_store.store_item.generic_item import GenericItem

class ForeignItem(GenericItem):
    """Item with a 20% price increase for foreign items."""
    def get_price(self) -> float:
        return self.price * 1.2
