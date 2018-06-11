/*
	Axel Yates
	Assignment 7
*/

package IR;

public class NewArrayIR extends Quadruple
{
	//x := new TYPE, SIZE
	public NewArrayIR(Object TYPE, Object SIZE, Object x)
	{
		op = "new";        //new
		arg1 = TYPE;       //TYPE
		arg2 = SIZE;       //SIZE
		result = x;        //x
	}
	
	public String toString()
	{
		return result + " := " + op + " " + arg1 + ", " + arg2;
	}
}