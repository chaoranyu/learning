#! /usr/bin/python3

# range
for value in range(1, 5):
	print(value)

# range to list
numbers = list(range(1, 6))
print(numbers)

# even numbers
even_numbers = list(range(2, 11, 2))
print(even_numbers)

# squares
squares = []
for value in range(1, 11):
	square = value ** 2
	squares.append(square)

print(squares)

# squares 2
squares = []
for value in range(1, 11):
	squares.append(value ** 2)

print(squares)

# squares 3: list comprehensions
squares = [value ** 2 for value in range(1, 11)]
print(squares)

# simple statistics
digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print("min(digits) = " + str(min(digits)))
print("max(digits) = " + str(max(digits)))
print("sum(digits) = " + str(sum(digits)))

# slices
print("The first three items in the list are:")
for digit in digits[:3]:
	print(digit)

print("Three items from the middle of the list are:")
for digit in digits[3:6]:
	print(digit)

print("The last three items in the list are:")
for digit in digits[-3:]:
	print(digit)

# range
print("The first three items in the list are:")
for i in range(0,3):
	print(digits[i])

print("Three items from the middle of the list are:")
for i in range(3,6):
	print(digits[i])

print("The last three items in the list are:")
for i in range(7,10):
	print(digits[i])




