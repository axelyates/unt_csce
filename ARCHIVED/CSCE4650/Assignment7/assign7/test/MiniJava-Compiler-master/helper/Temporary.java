/*
	Axel Yates
	Assignment 7
*/

package helper;

public class Temporary
{
	private static int nextNumber;
	private final int num;
	
	public Temporary()
	{
		num = nextNumber++;
	}
	
	public String toString()
	{
		return "t" + num;
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