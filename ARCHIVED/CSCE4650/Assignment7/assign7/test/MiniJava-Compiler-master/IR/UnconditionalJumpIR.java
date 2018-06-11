/*
	Axel Yates
	Assignment 7
*/

package IR;

public class UnconditionalJumpIR extends Quadruple
{
	//goto LABEL
	public UnconditionalJumpIR(Object label)
	{
		op = "goto";      //goto
		arg1 = null;
		arg2 = null;
		result = label;   //LABEL
	}
	
	public String toString()
	{
		return op + " " + result;
	}
}