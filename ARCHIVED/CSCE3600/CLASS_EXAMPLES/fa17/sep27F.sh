#! /bin/bash
trap 'justonce' 2
justonce()
{
	set -xv
	echo "not yet"
	trap 2	# now reset it
	set +xv
}
while true; do
	echo -n "."
		sleep 1
done

