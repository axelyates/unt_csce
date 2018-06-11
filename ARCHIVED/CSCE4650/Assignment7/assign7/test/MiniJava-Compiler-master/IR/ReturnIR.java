/*
	Axel Yates
	Assignment 7
*/

package IR;

public class ReturnIR extends Quadruple
{
	//return y
	public ReturnIR(Object y)
	{
		op = "return";   //return
		arg1 = y;        //y
		arg2 = null;
		result = null;
	}
	
	public String toString()
	{
		return op + " " + arg1;
	}
}