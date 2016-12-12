#!/bin/bash

menu=( "Apple" "Grape" "Orange" )

PS3="Which do you like?"

select item in ${menu[@]}; do
	echo "like $item"
done
