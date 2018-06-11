#! /bin/bash

if test -w "$1"
then
	echo "file $1 is writeable"
else
	echo "file $1 is NOT writeable"
fi

if [ -s $HOME/public/csce3600/fa17/$1 -a -r "$1" ]
then
	echo "file $1 is not empty and readable"
fi

if [ -d $HOME/public/csce3600/fa17 ]
then
	echo "file $HOME/public/csce3600/fa17 is a directory"
fi

if test -z "$2"
then
	echo "string $2 length is zero"
else
	echo "string $2 length is NOT zero"
fi

