#! /bin/bash
# plain kill or kill –9 will kill this

trap 'echo 1' 1
trap 'echo 2' 2

while true
do
	echo -n .
	sleep 1
done

