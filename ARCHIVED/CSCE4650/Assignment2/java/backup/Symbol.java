// Symbol class definition
// Symbol is a class to represent lexical tokens in the PL/0 
// programming language, described in Algorithms + Data
// Structures = Programs by Niklaus Wirth, Prentice-Hall, 1976.

public class Symbol {    // token classes
  public static final int EOF       = -1;
  public static final int BEGIN     =  0;
  public static final int CALL      =  1;
  public static final int CONST     =  2;
  public static final int DO        =  3;
  public static final int END       =  4;
  public static final int IF        =  5;
  public static final int ODD       =  6;
  public static final int PROC      =  7;
  public static final int THEN      =  8;
  public static final int VAR       =  9;
  public static final int WHILE     = 10;
  public static final int ID        = 11;
  public static final int INTEGER   = 12;
  public static final int ASSIGN    = 13;
  public static final int CLASS		= 14;
  public static final int COMMENT	= 15;
  public static final int IMPORT	= 16;
  public static final int PUBLIC	= 17;
  public static final int STATIC	= 18;
  public static final int VOID		= 19;
  public static final int MAIN		= 20;
  public static final int INT		= 21;
  public static final int STRING	= 22;
  public static final int ARGS		= 23;
  public static final int NEW		= 24;
  public static final int SYSTEM	= 25;
  public static final int OUT		= 26;
  public static final int PRINTLN	= 27;
  public static final int RETURN	= 28;
  public static final int SCANNER	= 29;
  public static final int NEXTINT	= 30;
  public static final int FACTO		= 31;
  public static final int INITIALIZE = 32;
  public static final int THIS		= 33;
  public static final int BOOLEAN	= 34;
  public static final int ELSE		= 35;
  public static final int IN		= 36;
  public static final int UNDERSCORE = '_';
  public static final int BAR 		= '|';
  public static final int PLUS 	    = '+';
  public static final int MINUS     = '-';
  public static final int TIMES     = '*';
  public static final int SLASH     = '/';
  public static final int EQ        = '=';
  public static final int LT        = '<';
  public static final int GT        = '>';
  public static final int NE        = GT + 1;
  public static final int LE        = NE + 1;
  public static final int GE        = LE + 1;
  public static final int AND       = GE + 1;
  public static final int LCURLY    = '{';
  public static final int RCURLY    = '}';
  public static final int LSQUARE   = '[';
  public static final int RSQUARE   = ']';
  public static final int LPAREN    = '(';
  public static final int RPAREN    = ')';
  public static final int COMMA     = ',';
  public static final int PERIOD    = '.';
  public static final int SEMICOLON = ';';
  public static final int COLON = ':';
}
