/*
	Axel Yates
	Assignment 7
*/

package IR;

public class CopyIR extends Quadruple
{
	//x := y
	public CopyIR(Object argument1, Object result)
	{
		op = null;
		arg1 = argument1;     //y
		arg2 = null;
		this.result = result; //x
	}
	
	public String toString()
	{
		return result + " := " + arg1;
	}
}