#! /bin/bash
# compute the average weekly temperature

TempTotal=0.0
for num in 1 2 3 4 5 6 7
do
	read -p "Enter temp for day $num: " Temp
	TempTotal=`echo "$TempTotal+$Temp" | bc -l`
done

AvgTemp=`echo "scale = 2; $TempTotal/7" | bc -l`
# AvgTemp=`echo $TempTotal/7 | bc -l`
echo "Average temperature: " $AvgTemp

