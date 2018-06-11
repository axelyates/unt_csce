#! /bin/bash
# kill –1 won’t kill this process
# kill –2 will (may not always work)

trap 'echo do not hang up' 1

while true
do
	echo "try to hang up"
	sleep 1
done
