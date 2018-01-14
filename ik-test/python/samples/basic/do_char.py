#!/usr/bin/env python3
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    print('包含中文的str')

    print("ord('A') =", ord('A'))
    print("ord('中') =", ord('中'))
    print("chr(66) =", chr(66))
    print("chr(25991) =", chr(25991))
    print('\u4e2d\u6587')

    print('ABC'.encode('ascii'))
    print('ABC'.encode('utf-8'))
    print('中文'.encode('utf-8'))
    print('中文'.encode('gb2312'))

    print(b'ABC'.decode('ascii'))
    print(b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8'))
    print(b'\xe4\xb8\xad\xe6\x96\x87\xff'.decode('utf-8', errors='ignore'))

    print("len('ABC') =", len('ABC'))
    print("len('中文') =", len('中文'))

    print("len(b'ABC') =", len(b'ABC'))
    print(r"len(b'\xe4\xb8\xad\xe6\x96\x87') =", len(b'\xe4\xb8\xad\xe6\x96\x87'))
    print("len('中文'.encode('utf-8)) =", len('中文'.encode('utf-8')))

    # format
    print('Hello, %s' %'world')
    print('Hi, %s, you have $%d' %('Michael', 10000))
    print('Hello, {0}, your score is up by {1:.1f}%'.format('Jack', 17.125))


    s1 = 72
    s2 = 85
    r = (s2 - s1) / s1 * 100
    print('%4.1f' %r)




