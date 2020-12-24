#!/usr/bin/python3

# Preventing a function from modifying a dictionary ?
def print_names(unprinted_names, completed_names):
    """
    Simulate printing each name, until none are left.
    Move each name to completed_names after printing.
    """
    for k, v in list(unprinted_names.items()):
        print(f"Printing name: {k} : {v}")
        del(unprinted_names[k])
        completed_names[k] = v

def show_completed_names(completed_names):
    """Show all the names that are printed."""
    print("\nThe following names have been printed:")
    for k, v in completed_names.items():
        print(f"{k}, {v}")

unprinted_names = {'first': 'burce', 'last': 'lee'}
completed_names = {}

print(f"Before: {unprinted_names}\n")

print_names(unprinted_names, completed_names)
show_completed_names(completed_names)

print(f"\nAfter: {unprinted_names}")
