#! /usr/bin/python3

# Using get() to access values
print("# Using get() to access values")
alien_0 = {'color': 'green', 'speed' : 'medium'}

point_value = alien_0.get('points', 'No point value assigned.')
print(point_value)
