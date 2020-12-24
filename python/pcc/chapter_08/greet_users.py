#!/usr/bin/python3

def greet_users(names):
    """Print a simple greeting to each other in the list."""
    for name in names:
        msg = f"Hello, {name.title()}"
        print(msg)

user_names = ['hannah', 'ty', 'margot']
greet_users(user_names)
