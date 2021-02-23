#!/usr/bin/env python3.9

# Positional arguments.
# def describe_pet(animal_type, pet_name):
#     ''' Display information about a pet. '''
#     print(f"\nI have a {animal_type}.")
#     print(f"My {animal_type}'s name is {pet_name.title()}.")
# 
# describe_pet('hamster', 'harry')
# describe_pet("dog", "willie")
 
# Keyword arguments.
# def describe_pet(animal_type, pet_name):
#     ''' Display information about a pet. '''
#     print(f"\nI have a {animal_type}.")
#     print(f"My {animal_type}'s name is {pet_name.title()}.")
# 
# describe_pet(animal_type = 'hamster', pet_name = 'harry')
# describe_pet(pet_name = 'harry', animal_type = 'hamster')
 
# Default values
# def describe_pet(animal_type = 'dog', pet_name):
# def describe_pet(pet_name, animal_type = 'dog'):
#     ''' Display information about a pet. '''
#     print(f"\nI have a {animal_type}.")
#     print(f"My {animal_type}'s name is {pet_name.title()}.")
# 
# describe_pet(pet_name = 'willie')
# describe_pet(animal_type = 'hamster', pet_name = 'harry')

def describe_pet(pet_name, animal_type='dog'):
    ''' Display information about a pet. '''
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

# A dog named Willie.
describe_pet('willie')
describe_pet(pet_name='willie')

# A hamster named Harry.
describe_pet('harry', animal_type='hamster')
describe_pet(animal_type='hamster', pet_name='harry')
describe_pet(pet_name='harry', animal_type='hamster')
