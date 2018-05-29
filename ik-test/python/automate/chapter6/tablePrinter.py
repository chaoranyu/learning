#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# tablePrinter.py - Print list in a pretty format.

def printTable(inList):
    colWidths = [0] * len(inList)
    for x in range(len(inList)):
        for i in inList[x]:
            if (len(i) > colWidths[x]):
                colWidths[x] = len(i)
    #print(colWidths)
    if colWidths[0] == 0:
        return
    for y in range(len(inList[0])):
        for x in range(len(inList)):
            print(inList[x][y].rjust(colWidths[x]), end = ' ')
        print()

tableData = [['apples', 'oranges', 'cherries', 'banana'],
             ['Alice', 'Bob', 'Carol', 'David'],
             ['dogs', 'cats', 'moose', 'geese']]
printTable(tableData)
