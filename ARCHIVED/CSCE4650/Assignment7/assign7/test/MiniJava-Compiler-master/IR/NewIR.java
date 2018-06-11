/*
	Axel Yates
	Assignment 7
*/

package IR;

public class NewIR extends Quadruple
{
	//x := new TYPE
	public NewIR(Object TYPE, Object x)
	{
		op = "new";        //new
		arg1 = TYPE;       //TYPE
		arg2 = null;
		result = x;        //x
	}
	
	public String toString()
	{
		return result + " := " + op + " " + arg1;
	}
}