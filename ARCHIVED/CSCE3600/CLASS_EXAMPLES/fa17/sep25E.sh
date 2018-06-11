#! /bin/bash
testfile()
{
	if [ $# -gt 0 ]; then
		if [[ -f $1 && -r $1 ]]; then
			echo $1 is a readable file
		else
			echo $1 is not a readable file
		fi
	fi
}
testfile .
testfile funtest

