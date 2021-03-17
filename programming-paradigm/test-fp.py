#!/usr/bin/env python3.9

# Assigning a function to a variable
def square(n):
    return n**2

f = square
print(f(10))

# Anonymous function
square = lambda x : x**2
print(square(10))

# Nested function
def outer():
    s = "hello"
    def inner():
        print(s)

    inner()
    s = "world"
    inner()

outer()

# map(func, iter)
lst = [1, 2, 3]
print(list(map(square, lst)))

# filter(func, iter)
def odd(n):
    return (n%2) == 1

print(list(filter(odd, lst)))
print(list(filter(lambda n: (n%2)==1, lst)))

# Eliminate the control flow
def func1(old_lst):
    new_lst = []
    for n in old_lst:
        if odd(n):
            new_lst.append(square(n))
    return new_lst

def func2(lst):
    return map(square, filter(odd, lst))

print(func1(lst))
print(list(func2(lst)))

# List comprehension
print(list(filter(lambda n: (n%2)==1, lst)))
print([n for n in lst if (n%2)==1])

# List comprehension
width = [1, 2, 3, 4]
height = [1, 2, 3, 4]

for w in width:
    for h in height:
        if w*h > 10:
            print(w*h)

print([w*h for w in width for h in height if w*h > 10])

# Closure
def d(f):
    def calc(x):
        dx = 0.000001
        return (f(x+dx) - f(x)) / dx
    return calc

# x^2+x+1
f = lambda x: x**2 + x + 1

f1 = d(f)
print(f1(3))

f2 = d(f1)
print(f2(3))
