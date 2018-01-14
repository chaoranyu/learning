#!/usr/bin/env python3
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    classmates = ['Aaron', 'Bruce', 'Cherry']
    print('classmates = ', classmates)
    print('len(classmates) = ', len(classmates))
    print('classmates[0] = ', classmates[0])
    print('classmates[1] = ', classmates[1])
    print('classmates[2] = ', classmates[2])
    print('classmates[-1] = ', classmates[-1])
    classmates.pop()
    print('classmates = ', classmates)
    classmates.append('Betty')
    classmates.insert(1, 'Ada')
    print('classmates = ', classmates)

    L = []
    print('len(L) = ', len(L))
    L = ['Apple', 123, True]
    print('L =', L)

    s = ['python', 'java', ['asp', 'php'], 'schema']
    print('s =', s)
