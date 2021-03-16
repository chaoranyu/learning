#!/usr/bin/env python3.9

# def process(num):
#     # filter out non-evens
#     if num % 2 != 0:
#         return
#     num = num * 3
#     #num = 'The Number: %s' % num
#     num = f'The Number: {num}'
#     return num
#  
# nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
#  
# for num in nums:
#     print(process(num))

# def even_filter(nums):
#     return filter(lambda x: x%2==0, nums)
# 
# def multiply_by_three(nums):
#     return map(lambda x: x*3, nums)
# 
# def convert_to_string(nums):
#     return map(lambda x: f'The number: {x}', nums)
# 
# nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# pipeline = convert_to_string(multiply_by_three(even_filter(nums)))
# for num in pipeline:
#     print(num)

class Pipe(object):
    def __init__(self, func):
        self.func = func
 
    def __ror__(self, other):
        def generator():
            for obj in other:
                if obj is not None:
                    yield self.func(obj)
        return generator()
 
@Pipe
def even_filter(num):
    return num if num % 2 == 0 else None
 
@Pipe
def multiply_by_three(num):
    return num*3
 
@Pipe
def convert_to_string(num):
    return 'The Number: %s' % num
 
@Pipe
def echo(item):
    print(item)
    return item
 
def force(sqs):
    for item in sqs: pass
 
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 
force(nums | even_filter | multiply_by_three | convert_to_string | echo)
