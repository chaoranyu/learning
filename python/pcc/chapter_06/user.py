#! /usr/bin/python3

# Looking through all key-value pairs
print("# Looking through all key-value pairs")

user_0 = {
    'username': 'efermi',
    'first' : 'enrico',
    'last' : 'fermi',
    }

for k, v in user_0.items():
    print(f"\nKey: {k}")
    print(f"Value: {v}")
