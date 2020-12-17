#! /usr/bin/python3

# A simple dictionary
print("# A simple dictionary")
alien_0 = {'color': 'green', 'points' : 5}

print(alien_0['color'])
print(alien_0['points'])

# Accessing values in dictionary
print("\n# Accessing values in dictionary")
alien_0 = {'color': 'green', 'points' : 5}

new_points = alien_0['points']
print(f"You just earned {new_points} points.")

# Adding new key-value pairs
print("\n# Adding new key-value pairs")
alien_0 = {'color': 'green', 'points' : 5}
print(alien_0)

alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)

# Staring with an empty dictionary
print("\n# Staring with an empty dictionary")
alien_0 = {}
print(alien_0)

alien_0['color'] = 'green'
alien_0['points'] = 5
print(alien_0)

# Modifying values in a dictionary
print("\n# Modifying values in a dictionary")
alien_0 = {'color': 'green'}
print(f"The alien is {alien_0['color']}.")

alien_0['color'] = 'yellow'
print(f"The alien now is {alien_0['color']}.")

# Modifying values in a dictionary
print("\n# Modifying values in a dictionary")
alien_0 = {'x_position' : 0, 'y_position' : 25, 'speed': 'medium'}
print(f"Original x-position: {alien_0['x_position']}.")

# Move the alien to the right.
# Determine how far to move the alien based on the current speed.
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    # This must be a fast alien
    x_increment = 3
    
alien_0['x_position'] = alien_0['x_position'] + x_increment
print(f"New x-position: {alien_0['x_position']}.")

# Removing key-value pairs
print("\n# Removing key-value pairs")
alien_0 = {'color': 'green', 'points' : 5}
print(alien_0)

del(alien_0['points'])
print(alien_0)
