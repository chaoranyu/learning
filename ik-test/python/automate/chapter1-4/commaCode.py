#!/usr/bin/env python3
# -*- charset: utf-8 -*-

def listToString(someList):
    newString = ''
    for i in someList:
        if someList.index(i) == len(someList) - 1:
            newString += str(i)
        elif someList.index(i) == len(someList) - 2:
            newString += str(i) + ', and '
        else:
            newString += str(i) + ', '
    return newString

fruits = ['apples', 'bananas', 'tofu', 'cats']
print('fruits: ' + listToString(fruits))

pets = ['Garfiled']
print('pets: ' + listToString(pets))

spam = ['']
print('spam: ' + listToString(spam))

foo = []
print('foo: ' + listToString(foo))
