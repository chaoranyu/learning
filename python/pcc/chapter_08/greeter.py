#!/usr/bin/python3.9

# Define a function.
# def greet_user():
#     ''' Display a simple greeting. '''
#     print("Hello!")
# 
# greet_user()
 
# Passing information to a function.
# def greet_user(username):
#     ''' Display a simple greeting. '''
#     print(f"Hello, {username.title()}!")
# 
# greet_user("jesse")

def get_formatted_name(first_name, last_name):
    ''' Return a full name, neatly formatted. '''
    full_name = f"{first_name} {last_name}"
    return full_name.title()

# This is an infinite loop.
while True:
    print("\nPlease tell me your name:")
    print("(enter 'q' at anytime to quit)")

    f_name = input("First name: ")
    if f_name == 'q':
        break;

    l_name = input("Last name: ")
    if l_name == 'q':
        break;

    formatted_name = get_formatted_name(f_name, l_name)
    print(f"\nHello, {formatted_name.title()}!")