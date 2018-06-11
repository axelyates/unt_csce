/*
  Name:       Axel Yates
  Assignment: Assignment 5
*/

import java.util.*;

enum Category {CLASS, FUNCTION, VARIABLE}

class Type { }

class IntegerType extends Type {
  public String toString () {
    return "int";
  }
}

class BooleanType extends Type {
  public String toString () {
    return "boolean";
  }
}

class VoidType extends Type {
  public String toString () {
    return "void";
  }
}

class ArrayType extends Type {
  private int dimension;
  private Type baseType;
  public ArrayType (int dim, Type base) {
    dimension = dim;
    baseType = base;
  }
  public int dimension () { return dimension; }
  public String toString () {
    return "array (" + dimension + ", " + baseType + ")";
  }
}

class ObjectType extends Type {
  private String className;
  private SymbolTableEntry objectType;
  public ObjectType (String className, SymbolTableEntry objectType) {
    this . className = className;
    this . objectType = objectType;
  }
  public String className () { return className; }
  public SymbolTableEntry objectType () { return objectType; }
  public String toString () {
    return className;
  }
}

class Declarator {
  private String id;
  private Type type;
  public Declarator (String id, Type type) {
    this . id = id;
    this . type = type;
  }
  public String id () { return id; }
  public Type type () { return type; }
}

class ArrayDeclarator extends Declarator {
  private int subscriptNumber;
  public ArrayDeclarator (String id, Type type, int subscriptNumber) {
    super (id, type);
    this . subscriptNumber = subscriptNumber;
  }
  public int subscriptNumber () { return subscriptNumber; }
}

class SymbolTableEntry {
  private Category category;
  private LinkedList<Type> argTypes;
  private SymbolTable localEnv;
  private String funcCode;
  private boolean staticFlag;
  private Type type;


  public SymbolTableEntry (Category category) { 
    this . category = category;
  }

  public SymbolTableEntry (Category category, Type type) {
    this . category = category;
    this . type = type;
  }

  public SymbolTableEntry (Category category, Type type, boolean staticFlag) {
    this . category = category;
    this . type = type;
    this . staticFlag = staticFlag;
  }

  public SymbolTableEntry (Category category, SymbolTable env) {
    this . category = category;
    this . localEnv = env;
  }

  public SymbolTableEntry (Category category, Type type, boolean staticFlag, LinkedList<Type> argTypes, SymbolTable env) {
    this . category = category;
    this . type = type;
    this . staticFlag = staticFlag;
    this . argTypes = argTypes;
    this . localEnv = env;
  }

  public Category category () { return category; }

  public boolean staticFlag () { return staticFlag; }

  public Type type () { return type; }

  public SymbolTable localEnv () { return localEnv; }

  public String funcCode () { return funcCode; }

  public void setCode (String code) { funcCode = code; }

  public String toString () {
    String printString = category . name ();
    if (category == Category . VARIABLE || category == Category . FUNCTION) {
      if (staticFlag){
        printString = printString + " yes   ";
      }
      else{
        printString = printString + " no    ";
      }
      if (category == Category . VARIABLE){
        printString = printString + " " + type;
      }
      else{
        printString = printString + " " + argTypes + "->" + type;
      }
    }
    return printString;
  }

}

public class SymbolTable {
  private static int maxlen = 2;
  public static int maxLen () { return maxlen; }
  private SymbolTable parent;
  private TreeMap <String, SymbolTableEntry> table;
  public SymbolTable (SymbolTable staticParent) { 
    parent = staticParent;
    table = new TreeMap <String, SymbolTableEntry> (); 
  }

  public SymbolTable parent () { return parent; }
  public SymbolTableEntry entry (String id) {
    SymbolTableEntry idEntry = table . get (id);
    if (idEntry == null){
      if (parent == null){
        ErrorMessage . print ("Undeclared identifier: " + id);
      }
    }
      else{
        idEntry = parent . entry (id);
      }
    return idEntry;
  }

  public void enter (String id, SymbolTableEntry entry) {
    SymbolTableEntry idEntry = table . get (id);
    if (idEntry != null)
      ErrorMessage . print ("Identifier " + id + " already declared.");
    table . put (id, entry);
    if (id . length () > maxlen){
      maxlen = id . length ();
    }
  }

  public void enterVar (String id, Type type) { 
    enter (id, new SymbolTableEntry (Category . VARIABLE, type));
  }
    public void enterClass (String id, SymbolTable env) {
    enter (id, new SymbolTableEntry (Category . CLASS, env));
  }
  public void enterFunc (String id, Type type, boolean staticFlag,
      LinkedList<Type> argTypes, SymbolTable env) {
    enter (id, new SymbolTableEntry (Category . FUNCTION, type, staticFlag,
      argTypes, env));
  }
  public void enterVar (String id, Type type, boolean staticFlag) { 
    enter (id, new SymbolTableEntry (Category . VARIABLE, type, staticFlag));
  }
  public void enterFuncCode (String id, String code) {
    SymbolTableEntry idEntry = table . get (id);
    idEntry . setCode (code);
  }
  public void print (String blockName) {
    System . out . println ();
    System . out . println ("ID Table for " + blockName);
    System . out . print ("----------------");
    for (int i = 0; i < blockName . length (); i++)
      System . out . print ("-");
    System . out . println ();
    System . out . println ();
    System . out . print ("ID");
    for (int i = 2; i < maxLen (); i++)
      System . out . print (" ");
    System . out . println (" Category Static Type");
    System . out . print ("--");
    for (int i = 2; i < maxLen (); i++)
      System . out . print (" ");
    System . out . println (" -------- ------ ----");
    Iterator <Map . Entry <String, SymbolTableEntry>> envIterator = 
      table . entrySet () . iterator ();
    TreeMap <String, SymbolTableEntry> classAndFunctionList = 
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
      if (idEntry . category () == Category . CLASS || idEntry . category () == Category . FUNCTION){
        classAndFunctionList . put (id, idEntry);
      }
    }
    Iterator <Map . Entry <String, SymbolTableEntry>> classAndFunctionIterator =
      classAndFunctionList . entrySet () . iterator ();
    while (classAndFunctionIterator . hasNext ()) {
      Map . Entry <String, SymbolTableEntry> entry = classAndFunctionIterator . next ();
      String classOrFunctionName = entry . getKey ();
      SymbolTableEntry idEntry = entry . getValue ();
      idEntry . localEnv () . print (classOrFunctionName);
    }
  }

}
