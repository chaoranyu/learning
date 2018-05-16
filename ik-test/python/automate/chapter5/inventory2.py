#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# inventory2.py
def displayInventory(inventory):
    print('Inventory:')
    item_total = 0;
    for k, v in inventory.items():
        print(str(v) + ' ' + k) 
        item_total += v
    print('Total number of items: ' + str(item_total))

def addToInventory(inventory, addedItems):
    inv = inventory
    for i in addedItems:
        inv.setdefault(i, 0)
        inv[i] += 1
    return inv

inv = {'gold coin': 42, 'rope': 1}
#displayInventory(inv)

dragonRoot = ['gold coin', 'dagger', 'gold coin', 'gold coin', 'ruby']
inv = addToInventory(inv, dragonRoot)
displayInventory(inv)
