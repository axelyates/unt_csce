/*
  Name:       Axel Yates
  Assignment: Assignment 5
*/

import java_cup . runtime . *;

public class TinyJavaPars {

  public static void main (String args []) throws java.io.IOException {
    System . out . println ("Source:");
    System . out . println ("-------");
    System . out . println ();

    try {
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      TinyJavaParser parser = 
        new TinyJavaParser (new TinyJavaLexer (System . in, symbolFactory), 
          symbolFactory);
      parser . parse ();
    }
    catch (Exception e) {
      System . out . println ("Error");
    }
  }

}
