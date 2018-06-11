/*
    This is the main running program for the assignment
    Name:       Axel Yates - ary0012
    Date:       02/06/18
    Class:      CSCE4650-001
    Assignment: Assignment 2
*/

import java_cup.runtime.ComplexSymbolFactory;
import java_cup.runtime.SymbolFactory;

public class TinyjavaLex {

  private static final int MAX_TOKENS = 1000;

  public static void main (String args []) throws java.io.IOException {

    int i, n;
    java_cup.runtime.Symbol [] token = new java_cup.runtime.Symbol [MAX_TOKENS];
    SymbolFactory symbolFactory = new ComplexSymbolFactory ();
    TinyjavaLexer lexer = new TinyjavaLexer (System . in, symbolFactory);

    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ();

    n = -1;
    do {
      if (n < MAX_TOKENS)
        token [++n] = lexer . next_token ();
      else
	ErrorMessage . print (0, "Maximum number of tokens exceeded");
    } while (token [n] . sym != Symbol . EOF);

    System . out . println ();
    System . out . println ("List of Tokens");
    System . out . println ("--------------");
    System . out . println ();
    for (i = 0; i < n; i++)
      System . out . println (token [i]);
    System . out . println ();
  }
}
