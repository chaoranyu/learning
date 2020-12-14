#! /usr/bin/python3

motorcycles = ['honda', 'yamaha']
print(motorcycles)

# modify
motorcycles[0] = 'ducati'
print(motorcycles)

# append
motorcycles.append('suzuki')
print(motorcycles)

# insert
motorcycles.insert(0, 'honda')
print(motorcycles)

# del
motorcycles.append(motorcycles[1])
del(motorcycles[1])
print(motorcycles)

print("----------------------------------------")
motorcycles2 = motorcycles
print(motorcycles2)

# pop
popped_motorcycle = motorcycles.pop()
print(motorcycles)
print(popped_motorcycle)

first_owned = motorcycles.pop(0)
print("The first motorcycle I owned was a " + first_owned + ".")

print("----------------------------------------")
print(motorcycles2)
motorcycles2.insert(0, 'honda')
motorcycles2.insert(-1, 'ducati')
print(motorcycles)

motorcycles.insert(-1, 'ducati')
print(motorcycles)

# remove
too_expensive = 'ducati'
motorcycles.remove(too_expensive)
print(motorcycles)
motorcycles.remove(too_expensive)
print(motorcycles)
# motorcycles.remove(too_expensive)
# print(motorcycles)
print("\nA " + too_expensive.title() + " is too expensive for me.")
