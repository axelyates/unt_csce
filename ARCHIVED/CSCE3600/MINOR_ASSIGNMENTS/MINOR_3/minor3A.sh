#!/bin/bash

counter=$2
othercounter=$1

if [ -z $1 ];
    then
        echo "usage: ./minor3A.sh height width"
        exit 1
elif [ $1 -lt 2 ];
    then
        echo "error: height ($1) and width ($2) must be > 1"
        exit 1
elif [ -z $2 ];
    then
        echo "usage: ./minor3A.sh height width"
        exit 1
elif [ $2 -lt 2 ];
    then
        echo "error: height ($1) and width ($2) must be > 1"
        exit 1
fi

echo -e "+\c"
counter=`expr $counter - 2`
while [ $counter -ne 0 ]
do
    echo -e "-\c"
    counter=`expr $counter - 1`
done
echo "+"
othercounter=`expr $1 - 2`
counter=$2
counter=`expr $counter - 2`
while [ $othercounter -ne 0 ]
do
    echo -e "|\c"
    while [ $counter -ne 0  ]
    do
        echo -e " \c"
        counter=`expr $counter - 1`
    done
    echo "|"
    counter=$2
    counter=`expr $counter - 2`
    othercounter=`expr $othercounter - 1`
done




counter=$2
echo -e "+\c"
counter=`expr $counter - 2`
while [ $counter -ne 0 ]
do
    echo -e "-\c"
    counter=`expr $counter - 1`
done
echo -e "+"
