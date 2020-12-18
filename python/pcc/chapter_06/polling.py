#! /usr/bin/python3

# Exercise 6.6

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

for name, language in favorite_languages.items():
    print(f"{name.title()}'s favorite language is {language.title()}.")
print("\n")

coders = ['ada', 'phil', 'mia', 'david', 'becca', 'edward']

for coder in coders:
    if coder in favorite_languages.keys():
        print(f"Thank you for taking the poll, {coder.title()}!")
    else:
        print(f"{coder.title()}, what's your favorite programming language?")
