/*
	Axel Yates
	Assignment 7
*/

package IR;

public class LengthIR extends Quadruple
{
	//x := length y
	public LengthIR(Object y, Object x)
	{
		op = "length";        //length
		arg1 = y;             //y
		arg2 = null;
		result = x;           //x
	}
	
	public String toString()
	{
		return result + " := " + op + " " + arg1;
	}
}