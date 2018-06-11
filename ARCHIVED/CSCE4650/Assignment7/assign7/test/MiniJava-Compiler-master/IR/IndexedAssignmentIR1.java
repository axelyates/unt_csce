/*
	Axel Yates
	Assignment 7
*/

package IR;

public class IndexedAssignmentIR1 extends Quadruple
{
	//x := y[i]
	public IndexedAssignmentIR1(Object y, Object i, Object x)
	{
		op = null;       
		arg1 = y;             //y
		arg2 = i;             //i
		result = x;           //x
	}
	
	public String toString()
	{
		return result + " := " + arg1 + "[" + arg2 + "]";
	}
}