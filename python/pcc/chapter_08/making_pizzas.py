#!/usr/bin/env python3.9

# # Importing an entire module
# import pizza
# 
# pizza.make_pizza(16, 'pepperoni')
# pizza.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# # Importing specific functions
# from pizza import make_pizza
# 
# make_pizza(16, 'pepperoni')
# make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# # Using as to give a function an alias
# from pizza import make_pizza as mp
# 
# mp(16, 'pepperoni')
# mp(12, 'mushrooms', 'green peppers', 'extra cheese')

# # Using as to give a module an alias
# import pizza as p
# 
# p.make_pizza(16, 'pepperoni')
# p.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# Importing all functions in a module
from pizza import *

make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
