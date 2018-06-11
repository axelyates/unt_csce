#! /bin/bash

directory=`echo */ | wc`
totaldirectories=`echo ${directory:14:1}`
files=`echo *.* | wc`
totalfiles=`echo ${files:14:1}`
totalbytes=0
executable=0
writeable=0     #I set all of these to 0 to make sure that when/if they weren't
direc=0         #+ used, they'd display 0 in the final table
file=0
nonexistent=0
filesum=0
finalfiles=`ls -l . | egrep -c '^-rwx'`
ordinaryfile=`ls -l . | egrep -c '^-rw-'`


if [ $1 ] #if arguments are supplied
then


    for var in "$@" 
    do #beginning of for loop

        findmyplace=`echo ${var:0}`

        existent=`ls -l . | egrep -c $var`

        if [ $existent == 0 ]
        then
            nonexistent=`expr $nonexistent + 1`
        fi

        if test -x "$var"
        then
            executable=`expr $executable + 1`
            continue
        fi

        if test -w "$var"
        then
            writeable=`expr $writeable + 1`
        fi 
        
        if test -d "$var"
        then
            direc=`expr $direc + 1`
        fi 

        if test -f "$var"
        then
            ordinaryfilesum=`wc -c < $var`
            file=`expr $file + 1`
            filesum=`expr $filesum + $ordinaryfilesum`
            
        fi 

    done #end of for loop

    echo "================= file data ================="
    echo "ordinary, readable, executable files  : $executable "
    echo "non-existent or other types of files  : $nonexistent "
    echo "directory files                       : $direc "
    echo "ordinary and readable files           : $file "
    echo "total bytes in ordinary files         : $filesum "

fi #end of if statement



if [ $# -eq 0 ] #if no arguments are supplied
then

    for temp in *
    do
        if test -x "$temp"
        then
            continue
        fi
        if test -f "$temp"
        then
            sumofsums=`wc -c < $temp`   #I understand that these are confusing names, however
            sumofsumofsums=`expr $sumofsumofsums + $sumofsums` #+ I wanted to make sure I knew where everything was going
        fi
    done


    echo "================= file data ================="
    echo "ordinary, readable, executable files  : $finalfiles "
    echo "non-existent or other types of files  : $nonexistent"
    echo "directory files                       : $totaldirectories "
    echo "ordinary and readable files           : $ordinaryfile "
    echo "total bytes in ordinary files         : $sumofsumofsums "
fi
