#! /bin/bash

pizza=(pineapple margherita alfredo barbeque)

for type in ${pizza[*]}
do
	echo "Enjoy your $type pizza!"
done
