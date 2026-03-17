"""Functions to keep track and alter inventory."""


def create_inventory(items: list):
    """Create a dict that tracks the amount (count) of each element on the `items` list.

    :param items: list - list of items to create an inventory from.
    :return: dict - the inventory dictionary.
    """

    d = {}
    
    for it in items:
        if it not in d:
            d[it] = items.count(it)
        else:
            continue
            
    return d


def add_items(inventory, items):
    """Add or increment items in inventory using elements from the items `list`.

    :param inventory: dict - dictionary of existing inventory.
    :param items: list - list of items to update the inventory with.
    :return: dict - the inventory updated with the new items.
    """
    
    for it in items:
        if it not in inventory:
            inventory[it] = 1
        else:
            inventory[it] += 1
            
    return inventory


def decrement_items(inventory, items):
    """Decrement items in inventory using elements from the `items` list.

    :param inventory: dict - inventory dictionary.
    :param items: list - list of items to decrement from the inventory.
    :return: dict - updated inventory with items decremented.
    """

    for it in items:
        if it in inventory and inventory[it] > 0:
            inventory[it] -= 1
        else:
            continue
            
    return inventory


def remove_item(inventory: dict, item: str):
    """Remove item from inventory if it matches `item` string.

    :param inventory: dict - inventory dictionary.
    :param item: str - item to remove from the inventory.
    :return: dict - updated inventory with item removed. Current inventory if item does not match.
    """

    inventory.pop(item, None)
    
    return inventory


def list_inventory(inventory: dict):
    """Create a list containing only available (item_name, item_count > 0) pairs in inventory.

    :param inventory: dict - an inventory dictionary.
    :return: list of tuples - list of key, value pairs from the inventory dictionary.
    """

    lst = []
    
    for key, val in inventory.items():
        if val > 0:
            lst.append((key, val))
        
    return lst

