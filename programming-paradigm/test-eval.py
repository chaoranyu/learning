#!/usr/bin/env python3.9

# example 1
def foo(op, n1, n2):
    return eval(f"{n1} {op} {n2}")
    #return eval( "%d %s %d" % (n1, op, n2) )

print(foo("+", 2, 4))
print(foo("*", 3, 5))

# example 2
def foo(op, nums):
    expr = ""
    for n in nums[1:]:  # skip the first element
        expr += (op + str(n))
    return eval(str(nums[0]) + expr); # fill in the first element and evalute the value

print(foo("+", [9]))
print(foo("+", [2, 3, 4, 5]))
print(foo("*", [2, 3, 4, 5]))

# example 3
print(eval("2*3**2+3*3+1"))

# example 4

