import java_cup . runtime . *;

public class tjp {

  public static void main (String args []) throws java.io.IOException {
    System . out . println ("Source Program");
    System . out . println ("--------------");
    System . out . println ("");

    try {
      SymbolFactory symbolFactory = new ComplexSymbolFactory ();
      tjparser parser = 
        new tjparser (new tjlexer (System . in, symbolFactory));
      parser . parse ();
    }
    catch (Exception e) {
      System . out . println ("Error in invoking parser/lexer");
    }
  }

}
