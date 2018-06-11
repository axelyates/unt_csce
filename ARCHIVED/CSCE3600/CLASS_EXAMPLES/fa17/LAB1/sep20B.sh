#! /bin/bash
# call script with 1 parameter, your grade average
if [ $1 -lt 70 ]
then
	echo You shall not pass!
elif [ $1 -gt 70 ]
then
	echo Congratulations, you pass!
else
	echo You win the lottery!
fi
