#! /usr/bin/python3

# test function sort()
a = 1
print("\n## test {:03}".format(a))

cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Here is the original list:")
print(cars)

cars.sort()
print("\nHere is the sorted list:")
print(cars)

cars.sort(reverse=True)
print("\nHere is the reverse sorted list:")
print(cars)

# test function sorted()
a += 1
print("\n## test {:03}".format(a))

cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Here is the original list:")
print(cars)

print("\nHere is the sorted list:")
print(sorted(cars))

print("\nHere is the original list again:")
print(cars)

# test function reverse()
a += 1
print("\n## test {:03}".format(a))

cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Here is the original list:")
print(cars)

cars.reverse()
print("\nHere is the reverse list:")
print(cars)

# test function len()
a += 1
print("\n## test {:03}".format(a))

cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Here is the original list:")
print(cars)
print("\nThe length of the list is:")
print(len(cars))
