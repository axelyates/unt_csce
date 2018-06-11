#! /bin/bash
global="pretty good variable"
checkvar()
{
	local inside="not so good variable"
	echo $global
	echo $inside
	global="better variable"
}

echo $global
checkvar
echo $global
echo $inside

