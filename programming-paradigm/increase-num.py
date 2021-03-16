#!/usr/bin/env python3.9

def inc(x):
    def incx(y):
        return x+y
    return incx

inc2 = inc(2)
inc5 = inc(5)

print(inc2(5))
print(inc5(5))

print(inc(3)(33))
