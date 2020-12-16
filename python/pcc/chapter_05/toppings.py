#! /usr/bin/python3

# if statement
requested_topping = 'mushrooms'

if requested_topping != 'anchovies':
    print("Hold on anchovies!\n")

# multiple if statements
# requested_topping = ('mushrooms', 'extra cheese')
requested_toppings = ['mushrooms', 'extra cheese']

if 'mushrooms' in requested_toppings:
    print("Add mushrooms.")
if 'papperoni' in requested_toppings:
    print("Add pepperoni.")
if 'extra cheese' in requested_toppings:
    print("Add extra cheese.")

print("\nFinished making your pizza!\n")

# multiple if statements
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']

for requested_topping in requested_toppings:
    print("Add " + requested_topping + ".")

print("\nFinished making your pizza!\n")

# Checking for special items
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("Sorry, we are out of green peppers right now.")
    else:
        print("Add " + requested_topping + ".")

print("\nFinished making your pizza!\n")

# Checking that a list is not empty
requested_toppings = [""]

if requested_toppings:
    for requested_topping in requested_toppings:
        print(f"Add {requested_topping}.")
        #print("Add " + requested_topping + ".")
    print("\nFinished making your pizza!\n")
else:
    print("Are you sure you want a plain pizza?\n")

# Using multiple lists
availabe_toppings = ['mushrooms', 'olives', 'green peppers',
                      'pepperoni', 'pineapple', 'extra cheese']

requested_toppings = ['mushrooms', 'french fries', 'extra cheese']
for requested_topping in requested_toppings:
    if requested_topping in availabe_toppings:
        print(f"Add {requested_topping}.")
        #print("Add " + requested_topping + ".")
    else:
        print(f"Sorry, we don't have {requested_topping}.")
        #print("Sorry, we don't have " + requested_topping + ".")

print("\nFinished making your pizza!")
