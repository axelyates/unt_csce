/*
	Axel Yates
	Assignment 7
*/

package IR;

public class IndexedAssignmentIR2 extends Quadruple
{
	//y[i] := x
	public IndexedAssignmentIR2(Object x, Object i, Object y)
	{
		op = null;       
		arg1 = x;             //x
		arg2 = i;             //i
		result = y;           //y
	}
	
	public String toString()
	{
		return result + "[" + arg2 + "]" + " := " + arg1;
	}
}