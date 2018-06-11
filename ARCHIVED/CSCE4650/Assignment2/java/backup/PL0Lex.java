// PL0Lex class 
// This class is a PL/0 lexical analyzer which reads a PL/0 source program 
// and outputs the list of tokens comprising that program. 

import java_cup.runtime.ComplexSymbolFactory;
import java_cup.runtime.SymbolFactory;

public class PL0Lex {

  private static final int MAX_TOKENS = 1000;

  public static void main (String args []) throws java.io.IOException {

    int i, n;
    java_cup.runtime.Symbol [] token = new java_cup.runtime.Symbol [MAX_TOKENS];
    SymbolFactory symbolFactory = new ComplexSymbolFactory ();
    PL0Lexer lexer = new PL0Lexer (System . in, symbolFactory);

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
