#!/bin/sh

MY_PATH="./lib"

if [ ! -d $MY_PATH ]; then
    echo "Dir $MY_PATH not exists."
    exit 1
fi

cd ${MY_PATH}

for file in `ls`
do
	echo -e ${file}": \c"
	objdump -g ${file} | grep debug -c
done
