#!/bin/bash
  
IFS=":"
while read -a arr
do
    echo "User : ${arr[0]} , Home Dir : ${arr[5]}"
done < ./user.txt
