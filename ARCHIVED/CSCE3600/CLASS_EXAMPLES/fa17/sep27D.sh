#! /bin/bash

trap 'echo SIGHUP will not work' 1
trap 'suppressonce' 2
suppressonce()
{
	echo "SIGINT suppressed"
	trap 2  # reset it (may not always work)
}
while true
do
	echo -n "."
	sleep 1
done 

