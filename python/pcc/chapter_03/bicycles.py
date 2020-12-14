#! /usr/bin/python3

# bicycles = ['trek', 'cannondale', 'redline', 'specialized', ]
# bicycles = ['trek', 'cannondale', 'redline', 'specialized', 3]
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles)

message = "My first bicycle was a " + bicycles[0].title() + "."
print(message)

# get last element of list
message = "My fourth bicycle was a " + bicycles[-1].title() + "."
print(message)

# test multiple types of list elements
test = ['test', 321, bicycles]
print(test)
