#! /bin/bash

# Good
while read OS VALUE
do
	echo "OS: $OS"
	echo "VALUE: $VALUE"
done < foo

# Bad
while read line
do
	OS=`echo $line | awk '{print $1}'`
	VALUE=`echo $line | awk '{print $2}'`
	echo "OS: $OS"
	echo "VALUE: $VALUE"
done < foo

# Good
cnt=1
while [ $cnt -ne 100 ]
do
	echo $cnt
	let cnt=cnt+1
done > bar

# Bad
cnt=1
while [ $cnt -ne 100 ]
do
	echo $cnt >> bar
	let cnt=cnt+1
done

DT=`date '+%Y%m%d'`
cnt=1
for i in `cat foo`
do
	# DT=`date '+%Y%m%d'` # bad
	FILE=${i}_${DT}
	echo $cnt > $FILE
	let cnt=cnt+1
done
