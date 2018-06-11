/*
  Name:       Axel Yates
  Assignment: Assignment 7
*/
import java_cup . runtime . *;

public class TinyJavaParsST {

  public static void main (String args []) throws java.io.IOException {
    System . out . println ("Source");
    System . out . println ("-------");
    System . out . println ();

    try {
	  String inputFileName = args [0] + ".java";
	  FileInputStream inputStream = new FileInputStream (inputFileName);
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      TinyJavaParserST parser = new TinyJavaParserST (new TinyJavaLexer (inputStream, symbolFactory);
      java_cup . runtime . Symbol parserValue = parser . parse ();
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
