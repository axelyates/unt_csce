/*
	Axel Yates
	Assignment 7
*/

package helper;

public class Label
{
	private static int nextNumber;
	private final int num;
	public boolean printBefore;
	
	public Label(boolean printBefore)
	{
		num = nextNumber++;
		this.printBefore = printBefore;
	}
	
	public String getName()
	{
		return "L" + num;
	}
	
	public String toString()
	{
		return "L" + num + ":";
	}
	
	public int getNum()
	{
		return num;
	}
	
	public void reset()
	{
		nextNumber = -1;
	}
}