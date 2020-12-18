#! /usr/bin/python3

# Store information about a pizza being ordered.
pizza = {
    'crust': 'thick',
    'toppings' : ['mushrooms', 'extra cheese'],
    }

# Summurize the order
print(f"You order a {pizza['crust']}-crust pizza "
    "with the following toppings:")

for topping in pizza['toppings']:
    print("\t" + topping)
