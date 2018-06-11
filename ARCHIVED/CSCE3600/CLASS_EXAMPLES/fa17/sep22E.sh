#! /bin/bash
for quizNum in 1 2 3 4 5
do
	read -p "Enter quiz #$quizNum: " score
	let sum=$sum+$score
done
let quizAvg=$sum/5
echo "Average quiz grade: $quizAvg"

