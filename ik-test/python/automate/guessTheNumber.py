#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# This is a guess number game
import random
secretNumber = random.randint(1, 64)
print('I am thinking a number between 1 and 64')

# Ask the player guess 6 times
for guessesTaken in range(1, 7):
    print('Take a guess.')
    guess = int(input())

    if guess < secretNumber:
        print('Your guess is too low.')
    elif guess > secretNumber:
        print('Your guess is too high.')
    else:
        break # This conidtion is the correct guess!
if guess == secretNumber:
    print('Good job, you guessed my number in ' + str(guessesTaken) + ' guesses!')
else:
    print('Nope. The number I was thinking of was ' + str(secretNumber))
