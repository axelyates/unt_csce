#! /bin/bash
fun()
{	# A somewhat more complex function.
	JUST_A_SECOND=1
	JUST_A_HALF_SECOND=0.5
	JUST_A_MILLISECOND=0.001
	let i=0
	REPEATS=30
	echo "And now the fun really begins."
	while [ $i -lt $REPEATS ]
	do
		echo "-------FUNCTIONS are fun-------->"
		sleep $JUST_A_MILLISECOND
		let i+=1
	done
}
fun

