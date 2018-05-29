#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# collatz.py: The Collatz Sequence
import sys

def collatz(initNumber):
    print(initNumber)
    if initNumber == 1:
        return 1

    if initNumber % 2 == 0:
        return collatz(initNumber // 2)
    else:
        return collatz(initNumber * 3 + 1)


print('Input a number: (empty to exit)')
while True:
    print('------------------------')
    try:
        inString = input()
        if inString == '':
            sys.exit()

        try:
            inNumber = int(inString)
        except:
            print('You must enter an integer.')
            continue

        collatz(inNumber)
    except KeyboardInterrupt:
        #print('force exit...')
        sys.exit()
