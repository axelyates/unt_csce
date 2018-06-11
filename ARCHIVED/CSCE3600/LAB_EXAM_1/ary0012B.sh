#! /bin/bash

product(){

    echo "You supplied command-linie arguments: $1 $2"    
    product=`expr $1 * $2`
    echo "The product is: $product"

}
if [ $# -gt 0  ];
then
    product $1 $2
else
    echo "enter a file"
fi
