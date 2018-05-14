#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# This is a program about Collatz Conjecture.
import sys
print('Input a number:')

def collatz(initNumber):
    print(initNumber)
    if initNumber == 1:
        return 1

    if initNumber % 2 == 0:
        return collatz(initNumber // 2)
    else:
        return collatz(initNumber * 3 + 1)


# Ask the player guess 6 times
while True:
    print('------------------------')
    try:
        inputStr = input()
        if inputStr == 'exit':
            sys.exit()

        try:
            number = int(inputStr)
        except:
            print('Error: Invalid argument.')
            continue

        collatz(number)
    except:
        print('force exit...')
        sys.exit()
