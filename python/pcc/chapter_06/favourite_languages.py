#! /usr/bin/python3

# A dictionary of similar objects
print("# A dictionary of similar objects")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

language = favorite_languages['sarah'].title()
print(f"Sarah's favorite language is {language}.")

# Looking through all key-value pairs
print("\n# Looking through all key-value pairs")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

for name, language in favorite_languages.items():
    print(f"{name.title()}'s favorite language is {language.title()}.")

# Looking through all the keys in dictionary
print("\n# Looking through all the keys in dictionary")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

# for name in favorite_languages.keys():
for name in favorite_languages: # default behavior
    print(f"{name.title()}")

# Looking through all the keys in dictionary
print("\n# Looking through all the keys in dictionary")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

friends = ['phil', 'sarah']
for name in favorite_languages.keys():
    print(f"Hi, {name.title()}.")
    if name in friends:
        language = favorite_languages[name].title()
        print(f'\t{name.title()}, I see you love {language}.')

# Looking through all the keys in dictionary
print("\n# Looking through all the keys in dictionary")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

if 'erin' not in favorite_languages.keys():
    print("Erin, please take our poll!")

# Looking through all the keys in dictionary
print("\n# Looking through all the keys in dictionary")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

for name in sorted(favorite_languages.keys()):
    print(f"{name.title()}, thank you for taking the poll.")

# Looking through all the values in dictionary
print("\n# Looking through all the values in dictionary")

favorite_languages = {
    'jen': 'python',
    'sarah' : 'c',
    'edward' : 'ruby',
    'phil' : 'python',
    }

print("The following languages have been mentioned:")
for language in sorted(set(favorite_languages.values())):
    print(language.title())

# A list in dictionary
print("\n# A list in dictionary")

favorite_languages = {
    'jen': ['python', 'ruby'],
    'sarah' : ['c'],
    'edward' : ['ruby', 'go'],
    'phil' : ['python', 'haskell'],
    }

for name, languages in favorite_languages.items():
    if len(languages) > 1:
        print(f"\n{name.title()}'s favorite languages are ")
    else:
        print(f"\n{language.title()}'s favorite language is ")
    for language in languages:
        print(f"\t{language.title()}")
