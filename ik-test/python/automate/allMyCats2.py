#!/usr/bin/env python3
# -*- charset: utf-8 -*-

catNames = []
while True:
    print('Enter the name of cat ' + str(len(catNames) + 1) +
            ' (Or enter nothing to stop.):')
    name = input()
    if name == '':
        break
    catNames = catNames + [name]    # list concatenation
print('The cat names are:')
for name in catNames:
    print('  ' + name)

# a skill: use range(len(someList)) in for loop
'''
supplies = ['pens', 'staplers', 'flame-throwers', 'binders']
for i in range(len(supplies)):
    print('Index ' + str(i) + ' in supplies is: ' + supplies[i])
'''
