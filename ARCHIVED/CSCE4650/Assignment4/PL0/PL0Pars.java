// PL0Pars.java

// This program is a parser for PL/0.  

import java_cup . runtime . *;

public class PL0Pars {

  public static void main (String args []) throws java.io.IOException {
    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ("");

    try {
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      PL0Parser parser = 
        new PL0Parser (new PL0Lexer (System . in, symbolFactory));
      parser . parse ();
    }
    catch (Exception e) {
      System . out . println ("Error in invoking parser/lexer");
    }
  }

}
