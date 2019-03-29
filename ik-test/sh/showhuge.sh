#! /bin/bash

if [ ! $1 ]; then
	num=80 
else
	num=$1
fi

echo "----------------------------------------------"
echo "total   free   | nr-0  free-0  | nr-1   free-1"
echo "----------------------------------------------"

multinodes=1
if [ ! -f "/sys/devices/system/node/node1/hugepages/hugepages-1048576kB/nr_hugepages" ]; then
    multinodes=0
fi	

while [ "$num" -gt 0 ]
do
	printf "%5s   " `grep "HugePages_Total" /proc/meminfo | tr -s ' ' | cut -f2 -d' '`
	printf "%4s   | " `grep "HugePages_Free" /proc/meminfo | tr -s ' ' | cut -f2 -d' '`
	printf "%4s  " `cat /sys/devices/system/node/node0/hugepages/hugepages-1048576kB/nr_hugepages`
	printf "%6s  | " `cat /sys/devices/system/node/node0/hugepages/hugepages-1048576kB/free_hugepages`
	#echo -e `cat /sys/devices/system/node/node1/hugepages/hugepages-1048576kB/nr_hugepages` "    \c"
    if [ $multinodes == 1 ]; then
	    printf "%4s   " `cat /sys/devices/system/node/node1/hugepages/hugepages-1048576kB/nr_hugepages`
	    printf "%6s   \n" `cat /sys/devices/system/node/node1/hugepages/hugepages-1048576kB/free_hugepages`
    else
        printf "%4s   %6s   \n" - -
    fi
	sleep 1
	let num--
done

echo
 
