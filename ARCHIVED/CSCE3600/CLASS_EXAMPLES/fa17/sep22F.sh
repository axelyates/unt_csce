#! /bin/bash

echo "Enter a floating-point number: "
read a

read -p "Enter another floating-point number: " b
#echo "Enter another floating-point number: " 
#read b

echo "$a+$b" | bc -l
