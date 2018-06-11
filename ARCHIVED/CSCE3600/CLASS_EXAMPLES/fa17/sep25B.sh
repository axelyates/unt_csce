#! /bin/bash
PS3="select entry or ^D: "
select var in alpha beta
do
	echo "$REPLY=$var"
done

