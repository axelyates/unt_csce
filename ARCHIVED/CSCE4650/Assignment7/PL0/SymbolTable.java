// SymbolTable.java

import java.util.*;

// SymbolTableEntry is a class to represent the symbol table entries
// for PL/0 programs.

class SymbolTableEntry {

  private int category;
  private int constValue;
  private SymbolTable procEnv;
  private String procCode;

  public SymbolTableEntry (int cat) { 
    category = cat;
  }

  public SymbolTableEntry (int cat, int val) {
    category = cat;
    constValue = val;
  }

  public SymbolTableEntry (int cat, SymbolTable env, String code) {
    category = cat;
    procEnv = env;
    procCode = code;
  }

  public int category () { return category; }

  public int value () { return constValue; }

  public SymbolTable procEnv () { return procEnv; }

  public String procCode () { return procCode; }

  public void enterCode (String code) { procCode = code; }

  public String toString () {
    String printString = Category . toString (category);
    if (category == Category . CONSTANT)
      printString = printString + "(" + constValue + ")";
    return printString;
  }

}
 
// SymbolTable is a class to represent the symbol table for PL/0 programs.

public class SymbolTable {

  private static int maxlen = 2; // for header "Id"

  public static int maxLen () { return maxlen; }

  private TreeMap <String, SymbolTableEntry> table; 	// id table

  public SymbolTable () { table = new TreeMap <String, SymbolTableEntry> (); }

  // The enter function enters an id and its information into the symbol
  // table.

  public void enter (String id, SymbolTableEntry entry) {
    table . put (id, entry);
    if (id . length () > maxlen)
      maxlen = id . length ();
  }

  // The enterConst function enters a constant id and its value into the 
  // symbol table.
 
  public void enterConst (String id, int value) { 
    enter (id, new SymbolTableEntry (Category . CONSTANT, value));
  }

  // The enterVar function enters a variable id into the symbol table.
 
  public void enterVar (String id) { 
    enter (id, new SymbolTableEntry (Category . VARIABLE));
  }

  // The enterProc function enters a procedure id into the symbol table, and
  // its local symbol table and code when available.

  public void enterProc (String id) {
    enter (id, new SymbolTableEntry (Category . PROCEDURE, null, ""));
  }

  public void enterProc (String id, SymbolTable env, String code) {
    enter (id, new SymbolTableEntry (Category . PROCEDURE, env, code));
  }

  // The entry function returns the symbol table entry for the id.

  public SymbolTableEntry entry (String id) {
    return table . get (id);
  }

  // The code function generates the code for the symbol table.

  public String code () {
    String genCode = "";
    Iterator <Map . Entry <String, SymbolTableEntry>> envIterator =
      table . entrySet () . iterator ();
    while (envIterator . hasNext ()) {
      Map . Entry <String, SymbolTableEntry> entry = envIterator . next ();
      String id = entry . getKey ();
      SymbolTableEntry idEntry = entry . getValue ();
      if (idEntry . category () == Category . VARIABLE)
        genCode = genCode + "  int " + id + ";\n";
    }
    return genCode;
  }

  // The print function prints the entire symbol table, including local
  // symbol tables and syntax trees for procedures.

  public void print (String blockName) {
    System . out . println ();
    System . out . println ("Identifier Table for " + blockName);
    System . out . print ("---------------------");
    for (int i = 0; i < blockName . length (); i++) 
      System . out . print ("-");
    System . out . println ();
    System . out . println ();
    System . out . print ("Id");
    for (int i = 2; i < maxLen (); i++)
      System . out . print (" ");
    System . out . println (" Category");
    System . out . print ("--");
    for (int i = 2; i < maxLen (); i++)
      System . out . print (" ");
    System . out . println (" --------");
    Iterator <Map . Entry <String, SymbolTableEntry>> envIterator = 
      table . entrySet () . iterator ();
    TreeMap <String, SymbolTableEntry> procedureList = 
      new TreeMap <String, SymbolTableEntry> ();
    while (envIterator . hasNext ()) {
      Map . Entry <String, SymbolTableEntry> entry = envIterator . next ();
      String id = entry . getKey ();
      SymbolTableEntry idEntry = entry . getValue ();
      System . out . print (id);
      for (int i = id . length (); i < maxLen (); i++)
        System . out . print (" ");
      System . out . print (" ");
      System . out . println (idEntry);
      if (idEntry . category () == Category . PROCEDURE)
        procedureList . put (id, idEntry);
    }
    Iterator <Map . Entry <String, SymbolTableEntry>> procedureIterator = 
      procedureList . entrySet () . iterator ();
    while (procedureIterator . hasNext ()) {
      Map . Entry <String, SymbolTableEntry> entry = 
        procedureIterator . next ();
      String procedureName = entry . getKey ();
      SymbolTableEntry idEntry = entry . getValue ();
      idEntry . procEnv () . print (procedureName);
    }
  }

}
