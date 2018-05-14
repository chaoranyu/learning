#!/usr/bin/env python3
# -*- charset: utf-8 -*-

def printGrid(someGrid):
    i = len(someGrid)
    j = len(someGrid[-1])
    for col in range(j):
        for row in range(i):
            print(someGrid[row][col], end = '')
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
print('>> One')
printGrid(grid)

grid = ['.', '.', 'O', 'O', '.', 'O', 'O', '.', '.']
print('\n>> Two:')
printGrid(grid)

grid = ['O']
print('\n>> Three:')
printGrid(grid)

grid = [[]]
print('\n>> Four:')
printGrid(grid)
