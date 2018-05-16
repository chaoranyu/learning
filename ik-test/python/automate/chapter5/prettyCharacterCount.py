#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import pprint

# This is a program about character counting
messages = 'It was a bright cold day in April1, and the clocks were striking thirteen.'
count = {}

for character in messages:
    count.setdefault(character, 0)
    count[character] = count[character] + 1

pprint.pprint(count)
# print(pprint.pformat(count))
