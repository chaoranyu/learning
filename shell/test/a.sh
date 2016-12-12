#!/bin/bash

your_name='ufo'
str="Hello, I know your are \"$your_name\"! \n"
echo $str
str='Hello, I know your are \"$your_name\"! \n'
echo $str
str='Hello, I know your are \\$your_name \\! \n'
echo $str

echo ${#str}
