#! /bin/bash

reply=$1

if [ $1 == "today" ];
    then
        date '+%A' 
elif [ $1 == "tomorrow" ];
    then
        date --date '+1 day' '+%A'
elif [ $1 == "yesterday" ];
    then
        date --date '-1 day' '+%A'
else
    echo "Invalid option. Use "yesterday", "today", or "tomorrow""
fi
