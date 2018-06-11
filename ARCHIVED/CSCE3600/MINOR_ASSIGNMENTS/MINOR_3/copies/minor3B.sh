#! /bin/bash


#echo "test below"
#echo `find . -executable`

count=0
for file in .*;
do
if [ -x $file ];
    then
    count=$((count+1));
fi
done
echo "total ${count}"








directory=`echo */ | wc`
totaldirectories=`echo ${directory:14:1}`
files=`echo *.* | wc`
totalfiles=`echo ${files:14:1}`

echo "files is $files"

echo "================= file data ================="
echo "ordinary, readable, executable files  : $totalfiles "
echo "non-existent or other types of files  : "
echo "directory files                       : $totaldirectories "
echo "ordinary and readable files           : "
echo "total bytes in ordinary files         : "
