// PL0ParsCode.java

// This program is a parser for PL/0 which contsructs the symbol table from
// the source program declarations.

import java.io.*;
import java_cup . runtime . *;

public class PL0ParsCode {

  public static void main (String args []) throws java.io.IOException {
    if (args . length != 1) 
      ErrorMessage . print ("File name expected");

    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ();

    try {
      String inputFileName = args [0] + ".pl0";
      FileInputStream inputStream = new FileInputStream (inputFileName);
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      PL0ParserCode parser = 
        new PL0ParserCode (new PL0Lexer (inputStream, symbolFactory));
      java_cup .runtime . Symbol parserValue = parser . parse ();
      Code code = (Code) parserValue . value;
      code . env () . print ("main");
      String outputFileName = args [0] + ".c";
      PrintStream outputStream = new PrintStream (outputFileName);
      outputStream . print (code . generate ("main"));
    }
    catch (Exception e) {
      System . out . println ("Exception:" + e);
      e . printStackTrace();
    }
  }

}
