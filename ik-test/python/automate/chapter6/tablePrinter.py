#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# tablePrinter.py - Print list in a pretty format.

def printTable(inputList):
    colWidths = [0] * len(inputList)
    for i in range(len(inputList)):
        for item in inputList[i]:
            if (len(item) > colWidths[i]):
                colWidths[i] = len(item)
    #print(colWidths)
    if colWidths[0] == 0:
        return
    for j in range(len(inputList[0])):
        for i in range(len(inputList)):
            print(inputList[i][j].rjust(colWidths[i]), end = ' ')
        print()

tableData = [['apples', 'oranges', 'cherries', 'banana'],
             ['Alice', 'Bob', 'Carol', 'David'],
             ['dogs', 'cats', 'moose', 'geese']]
printTable(tableData)
