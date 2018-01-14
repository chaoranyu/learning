#!/usr/bin/env python3
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    classmates = ('Aaron', 'Bruce', 'Cherry')
    print('classmates = ', classmates)
    print('len(classmates) = ', len(classmates))
    print('classmates[0] = ', classmates[0])
    print('classmates[1] = ', classmates[1])
    print('classmates[2] = ', classmates[2])
    print('classmates[-1] = ', classmates[-1])

    # cannot modify tuple
    # classmates[0] = 'Ada'
    print('classmates = ', classmates)

    t = ('a', 'b', ['A', 'B'])
    print('t =', t)
    t[2][0] = 'X'
    t[2][1] = 'YY'
    print('t =', t)
