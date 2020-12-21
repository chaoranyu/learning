#! /usr/bin/python3

# How the input function works
# prompt = "\nTell me something, and I will repeat back to you: "
# prompt += "\nEnter 'quit' to exit the program. "
#
# message = ""
# while message != 'quit':
#     message = input(prompt)
# 
#     if message != 'quit':
#         print(message)
# 

# sing a flag
prompt = "\nTell me something, and I will repeat back to you: "
prompt += "\nEnter 'quit' to exit the program. "

active = True
while active:
    message = input(prompt)

    if message == 'quit':
        active = False
    else:
        print(message)
