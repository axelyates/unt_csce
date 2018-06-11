// TinyJavaPars.java

// This program is a parser for TinyJava.  

import java_cup . runtime . *;

public class TinyJavaPars {

  public static void main (String args []) throws java.io.IOException {
    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ();

    try {
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      TinyJavaParser parser = 
        new TinyJavaParser (new TinyJavaLexer (System . in, symbolFactory), 
          symbolFactory);
      parser . parse ();
    }
    catch (Exception e) {
      System . out . println ("Error in invoking parser/lexer");
    }
  }

}
