#! /bin/bash

Again="Y"
while [ $Again = "Y" ]; do
	ps u
	read -p "Do you want to continue? (Y/N) " reply
	Again=`echo $reply | tr [:lower:] [:upper:]`
done
echo "done"

