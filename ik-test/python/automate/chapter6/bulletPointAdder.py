#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# bulletPointAdder.py - Add Wikipedia bullet points to the start
# of each line of text on the clipborad.

import pyperclip
text = pyperclip.paste()

# Seperate lines and add stars.
lines = text.spit('\n')
for i in range(len(lines)): # loop through all indexes for "lines" list
    lines[i] = '* ' + lines[i] # add star to each string in "lines" list
text = '\n'.join(lines)
pyperclip.clip(text)
