#!/usr/bin/env python3
# -*- charset: utf-8 -*-

# charGrid.py: Character Picture Grid
def printGrid(someGrid):
    for y in range(len(someGrid[0])):
        for x in range(len(someGrid)):
            print(someGrid[x][y], end = '')
        print()

grid = [['.', '.', '.', '.', '.', '.'],
        ['.', 'O', 'O', '.', '.', '.'],
        ['O', 'O', 'O', 'O', '.', '.'],
        ['O', 'O', 'O', 'O', 'O', '.'],
        ['.', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', '.'],
        ['O', 'O', 'O', 'O', '.', '.'],
        ['.', 'O', 'O', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.']]
printGrid(grid)
print('---------TEST2----------')

grid = ['.', '.', 'X', 'X', '.', 'X', 'X', '.', '.']
printGrid(grid)
print('---------TEST3----------')

grid = [['X', 'X', 'X']]
printGrid(grid)
print('---------TEST4----------')

grid = [[]]
printGrid(grid)
print('----------END-----------')
