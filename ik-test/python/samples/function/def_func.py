#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math

from abstest import my_abs

def move(x, y, step, angle=0):
    if (not isinstance(x, (int, float))
        or not isinstance(y, (int, float))
        or not isinstance(step, (int, float))
        or not isinstance(angle, (int, float))):
        raise TypeError('bad operand type')
    nx = x + step * math.cos(angle)
    ny = y - step * math.sin(angle)
    return nx, ny

def quadratic(a, b, c):
    for n in range(a, b, c):
        if not isinstance(n, (int, float)):
            raise TypeError('Bad operand type')

    if a == 0:
        raise TypeError('The quadratic coefficient cannot be 0')

    delta = b * b - 4 * a *c
    if delta < 0:
        return None
    else:
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        return (x1, x2)

n = my_abs(-20)
print(n)

# TypeError: bad operand type
#my_abs('123')


x, y = move(100, 100, 60, math.pi / 6)
print(x, y)


# 测试:
print('quadratic(2, 3, 1) =', quadratic(2, 3, 1))
print('quadratic(1, 3, -4) =', quadratic(1, 3, -4))

if quadratic(2, 3, 1) != (-0.5, -1.0):
    print('测试失败')
elif quadratic(1, 3, -4) != (1.0, -4.0):
    print('测试失败')
else:
    print('测试成功')
