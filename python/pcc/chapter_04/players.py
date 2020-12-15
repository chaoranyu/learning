#! /usr/bin/python3

# Slicing a list
players = ['charles', 'martina', 'michale', 'florence', 'eli']
print(players)
print(players[1:4])
print(players[:3])
print(players[1:])
print(players[-3:])

# Looping through a slice
players = ['charles', 'martina', 'michale', 'florence', 'eli']
print("Here are the first three players on my team:")
for player in players[:3]:
    print(player.title())
