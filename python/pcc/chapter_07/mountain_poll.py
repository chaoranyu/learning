#! /usr/bin/python3.9

# Fill a dictionary with user input
responses = {}

# Setting a flag to indicate that polling is active.
polling_active = True 

while polling_active:
    # Prompt for the person's name and response.
    name = input("\nWhat is your name? ")
    response = input("Which mountain would you climb someday? ")

    # Store the response in the dictionary.
    responses[name] = response

    # FInding out if anyone else is going to take the poll.
    response = input("Would you like to let another person respond? (yes/no) ")
    if response == 'no':
        polling_active = False

# Polling is completed. Show the results.
print("\n---- Poll Results ----")
for name, mountain in responses.items():
    print(f"{name.title()} would like to climb {mountain.title()}.")
