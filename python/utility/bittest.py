#! /usr/bin/python3

# if statement
def int_to_bin(num, bits=8):
    r = ''
    while bits:
        r = ('1' if num&1 else '0') + r
        bits = bits - 1
        num = num >> 1
        print(r)

if __name__ == '__main__':
    num = input("Enter a non-negative number less than 256: ")
    num = int(num)

    if num < 0:
        print("\nSorry, number must be non-negative!")
    elif num >= 256:
        print(f"\nSorry, {num} is not less than 256!")
    else:
        print()
        int_to_bin(num)
