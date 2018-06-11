/*
	Axel Yates
	Assignment 7
*/

package helper;

public class Token
{
	Object value;
	int line;
	int col;
	
	public Token(Object value, int line, int col)
	{
		this.value = value;
		this.line = line;
		this.col = col;
	}
	
	public Object getValue()
	{
		return value;
	}
	
	public int getLine()
	{
		return line;
	}
	
	public int getCol()
	{
		return col;
	}
}