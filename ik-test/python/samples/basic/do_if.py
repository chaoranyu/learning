#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# be careful
# input() reture a string
# use int() before comparing

if __name__ == '__main__':
    age = int(input('Input your age: '))

    if age >= 18:
        print('adult')
    elif age >= 12:
        print('teenager')
    else:
        print('kid')
