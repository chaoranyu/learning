#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# caculate 1+2+3+...+100
sum = 0
n = 1
while n <= 100:
    sum = sum + n
    n = n + 1
print(sum)

# caculate 1*2*3*...*100
acc = 1
n = 1
while n <= 100:
    acc *= n
    n += 1
print(acc)
