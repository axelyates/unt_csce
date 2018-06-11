#! /bin/bash
echo "Enter Y to see all the files including hidden files"
echo "Enter N to see all non-hidden files"
echo "Enter q to quit"

read -p "Enter your choice: " reply

case $reply in
Y|YES)	echo "Displaying all (really…) files"
	ls -a ;;
N|NO)	echo "Displaying all non-hidden files"
	ls ;;
*)	echo "Invalid choice! "; exit 1 ;;
esac

