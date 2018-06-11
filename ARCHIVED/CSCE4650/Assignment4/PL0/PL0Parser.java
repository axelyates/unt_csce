
//----------------------------------------------------
// The following code was generated by CUP v0.11a beta 20060608
// Wed Mar 28 10:45:13 CST 2018
//----------------------------------------------------

import java_cup.runtime.*;

/** CUP v0.11a beta 20060608 generated parser.
  * @version Wed Mar 28 10:45:13 CST 2018
  */
public class PL0Parser extends java_cup.runtime.lr_parser {

  /** Default constructor. */
  public PL0Parser() {super();}

  /** Constructor which sets the default scanner. */
  public PL0Parser(java_cup.runtime.Scanner s) {super(s);}

  /** Constructor which sets the default scanner. */
  public PL0Parser(java_cup.runtime.Scanner s, java_cup.runtime.SymbolFactory sf) {super(s,sf);}

  /** Production table. */
  protected static final short _production_table[][] = 
    unpackFromStrings(new String[] {
    "\000\051\000\002\002\004\000\002\002\004\000\002\003" +
    "\006\000\002\004\005\000\002\004\002\000\002\005\005" +
    "\000\002\005\007\000\002\006\005\000\002\006\002\000" +
    "\002\007\003\000\002\007\005\000\002\010\010\000\002" +
    "\010\002\000\002\011\005\000\002\011\004\000\002\011" +
    "\005\000\002\011\006\000\002\011\006\000\002\011\002" +
    "\000\002\012\003\000\002\012\005\000\002\013\004\000" +
    "\002\013\005\000\002\015\003\000\002\015\003\000\002" +
    "\015\003\000\002\015\003\000\002\015\003\000\002\015" +
    "\003\000\002\014\003\000\002\014\004\000\002\014\005" +
    "\000\002\017\003\000\002\017\003\000\002\016\003\000" +
    "\002\016\005\000\002\021\003\000\002\021\003\000\002" +
    "\020\003\000\002\020\003\000\002\020\005" });

  /** Access to production table. */
  public short[][] production_table() {return _production_table;}

  /** Parse-action table. */
  protected static final short[][] _action_table = 
    unpackFromStrings(new String[] {
    "\000\115\000\024\004\ufffd\021\ufffd\026\ufffd\027\ufffd\030" +
    "\004\033\ufffd\035\ufffd\037\ufffd\040\ufffd\001\002\000\004" +
    "\004\107\001\002\000\024\004\ufff9\020\ufff9\021\ufff9\026" +
    "\ufff9\027\ufff9\033\ufff9\035\ufff9\037\012\040\ufff9\001\002" +
    "\000\004\002\011\001\002\000\004\021\010\001\002\000" +
    "\004\002\000\001\002\000\004\002\001\001\002\000\004" +
    "\004\102\001\002\000\022\004\ufff5\020\ufff5\021\ufff5\026" +
    "\ufff5\027\ufff5\033\ufff5\035\ufff5\040\ufff5\001\002\000\022" +
    "\004\015\020\uffef\021\uffef\026\016\027\023\033\022\035" +
    "\020\040\021\001\002\000\004\025\100\001\002\000\020" +
    "\004\015\020\uffef\026\016\027\023\032\uffef\033\022\040" +
    "\021\001\002\000\006\020\uffff\021\uffff\001\002\000\004" +
    "\004\067\001\002\000\016\004\033\005\026\014\031\015" +
    "\025\023\036\034\032\001\002\000\016\004\033\005\026" +
    "\014\031\015\025\023\036\034\032\001\002\000\004\004" +
    "\024\001\002\000\010\020\ufff3\021\ufff3\032\ufff3\001\002" +
    "\000\010\004\uffe0\005\uffe0\023\uffe0\001\002\000\042\006" +
    "\uffda\007\uffda\010\uffda\011\uffda\012\uffda\013\uffda\014\uffda" +
    "\015\uffda\016\uffda\017\uffda\020\uffda\021\uffda\024\uffda\031" +
    "\uffda\032\uffda\036\uffda\001\002\000\004\036\062\001\002" +
    "\000\042\006\uffe4\007\uffe4\010\uffe4\011\uffe4\012\uffe4\013" +
    "\uffe4\014\uffe4\015\uffe4\016\043\017\042\020\uffe4\021\uffe4" +
    "\024\uffe4\031\uffe4\032\uffe4\036\uffe4\001\002\000\010\004" +
    "\uffe1\005\uffe1\023\uffe1\001\002\000\014\004\033\005\026" +
    "\014\031\015\025\023\036\001\002\000\042\006\uffdb\007" +
    "\uffdb\010\uffdb\011\uffdb\012\uffdb\013\uffdb\014\uffdb\015\uffdb" +
    "\016\uffdb\017\uffdb\020\uffdb\021\uffdb\024\uffdb\031\uffdb\032" +
    "\uffdb\036\uffdb\001\002\000\022\006\057\007\054\010\055" +
    "\011\052\012\053\013\056\014\031\015\025\001\002\000" +
    "\042\006\uffdf\007\uffdf\010\uffdf\011\uffdf\012\uffdf\013\uffdf" +
    "\014\uffdf\015\uffdf\016\uffdf\017\uffdf\020\uffdf\021\uffdf\024" +
    "\uffdf\031\uffdf\032\uffdf\036\uffdf\001\002\000\014\004\033" +
    "\005\026\014\031\015\025\023\036\001\002\000\010\004" +
    "\033\005\026\023\036\001\002\000\042\006\uffe3\007\uffe3" +
    "\010\uffe3\011\uffe3\012\uffe3\013\uffe3\014\uffe3\015\uffe3\016" +
    "\043\017\042\020\uffe3\021\uffe3\024\uffe3\031\uffe3\032\uffe3" +
    "\036\uffe3\001\002\000\010\004\033\005\026\023\036\001" +
    "\002\000\010\004\uffdc\005\uffdc\023\uffdc\001\002\000\010" +
    "\004\uffdd\005\uffdd\023\uffdd\001\002\000\042\006\uffde\007" +
    "\uffde\010\uffde\011\uffde\012\uffde\013\uffde\014\uffde\015\uffde" +
    "\016\uffde\017\uffde\020\uffde\021\uffde\024\uffde\031\uffde\032" +
    "\uffde\036\uffde\001\002\000\010\014\031\015\025\024\046" +
    "\001\002\000\042\006\uffd9\007\uffd9\010\uffd9\011\uffd9\012" +
    "\uffd9\013\uffd9\014\uffd9\015\uffd9\016\uffd9\017\uffd9\020\uffd9" +
    "\021\uffd9\024\uffd9\031\uffd9\032\uffd9\036\uffd9\001\002\000" +
    "\010\004\033\005\026\023\036\001\002\000\042\006\uffe2" +
    "\007\uffe2\010\uffe2\011\uffe2\012\uffe2\013\uffe2\014\uffe2\015" +
    "\uffe2\016\043\017\042\020\uffe2\021\uffe2\024\uffe2\031\uffe2" +
    "\032\uffe2\036\uffe2\001\002\000\014\004\033\005\026\014" +
    "\031\015\025\023\036\001\002\000\014\004\uffe5\005\uffe5" +
    "\014\uffe5\015\uffe5\023\uffe5\001\002\000\014\004\uffea\005" +
    "\uffea\014\uffea\015\uffea\023\uffea\001\002\000\014\004\uffe6" +
    "\005\uffe6\014\uffe6\015\uffe6\023\uffe6\001\002\000\014\004" +
    "\uffe7\005\uffe7\014\uffe7\015\uffe7\023\uffe7\001\002\000\014" +
    "\004\uffe9\005\uffe9\014\uffe9\015\uffe9\023\uffe9\001\002\000" +
    "\014\004\uffe8\005\uffe8\014\uffe8\015\uffe8\023\uffe8\001\002" +
    "\000\012\014\031\015\025\031\uffeb\036\uffeb\001\002\000" +
    "\012\014\031\015\025\031\uffec\036\uffec\001\002\000\022" +
    "\004\015\020\uffef\021\uffef\026\016\027\023\032\uffef\033" +
    "\022\040\021\001\002\000\010\020\ufff1\021\ufff1\032\ufff1" +
    "\001\002\000\004\031\065\001\002\000\022\004\015\020" +
    "\uffef\021\uffef\026\016\027\023\032\uffef\033\022\040\021" +
    "\001\002\000\010\020\ufff0\021\ufff0\032\ufff0\001\002\000" +
    "\004\020\070\001\002\000\024\004\ufffd\020\ufffd\026\ufffd" +
    "\027\ufffd\030\004\033\ufffd\035\ufffd\037\ufffd\040\ufffd\001" +
    "\002\000\004\020\072\001\002\000\022\004\ufff6\020\ufff6" +
    "\021\ufff6\026\ufff6\027\ufff6\033\ufff6\035\ufff6\040\ufff6\001" +
    "\002\000\006\020\uffee\032\uffee\001\002\000\006\020\075" +
    "\032\076\001\002\000\020\004\015\020\uffef\026\016\027" +
    "\023\032\uffef\033\022\040\021\001\002\000\010\020\ufff2" +
    "\021\ufff2\032\ufff2\001\002\000\006\020\uffed\032\uffed\001" +
    "\002\000\014\004\033\005\026\014\031\015\025\023\036" +
    "\001\002\000\014\014\031\015\025\020\ufff4\021\ufff4\032" +
    "\ufff4\001\002\000\006\020\ufff8\022\ufff8\001\002\000\006" +
    "\020\105\022\104\001\002\000\004\004\106\001\002\000" +
    "\022\004\ufffa\020\ufffa\021\ufffa\026\ufffa\027\ufffa\033\ufffa" +
    "\035\ufffa\040\ufffa\001\002\000\006\020\ufff7\022\ufff7\001" +
    "\002\000\004\012\116\001\002\000\006\020\112\022\111" +
    "\001\002\000\004\004\113\001\002\000\024\004\ufffe\020" +
    "\ufffe\021\ufffe\026\ufffe\027\ufffe\033\ufffe\035\ufffe\037\ufffe" +
    "\040\ufffe\001\002\000\004\012\114\001\002\000\004\005" +
    "\115\001\002\000\006\020\ufffb\022\ufffb\001\002\000\004" +
    "\005\117\001\002\000\006\020\ufffc\022\ufffc\001\002" });

  /** Access to parse-action table. */
  public short[][] action_table() {return _action_table;}

  /** <code>reduce_goto</code> table. */
  protected static final short[][] _reduce_table = 
    unpackFromStrings(new String[] {
    "\000\115\000\010\002\005\003\006\004\004\001\001\000" +
    "\004\005\107\001\001\000\004\006\012\001\001\000\002" +
    "\001\001\000\002\001\001\000\002\001\001\000\002\001" +
    "\001\000\004\007\102\001\001\000\004\010\013\001\001" +
    "\000\004\011\016\001\001\000\002\001\001\000\006\011" +
    "\072\012\073\001\001\000\002\001\001\000\002\001\001" +
    "\000\014\013\063\014\033\016\027\017\036\020\034\001" +
    "\001\000\014\013\026\014\033\016\027\017\036\020\034" +
    "\001\001\000\002\001\001\000\002\001\001\000\002\001" +
    "\001\000\002\001\001\000\002\001\001\000\004\021\040" +
    "\001\001\000\002\001\001\000\012\014\060\016\027\017" +
    "\036\020\034\001\001\000\002\001\001\000\006\015\050" +
    "\017\046\001\001\000\002\001\001\000\012\014\044\016" +
    "\027\017\036\020\034\001\001\000\006\016\037\020\034" +
    "\001\001\000\004\021\040\001\001\000\004\020\043\001" +
    "\001\000\002\001\001\000\002\001\001\000\002\001\001" +
    "\000\004\017\046\001\001\000\002\001\001\000\006\016" +
    "\047\020\034\001\001\000\004\021\040\001\001\000\012" +
    "\014\057\016\027\017\036\020\034\001\001\000\002\001" +
    "\001\000\002\001\001\000\002\001\001\000\002\001\001" +
    "\000\002\001\001\000\002\001\001\000\004\017\046\001" +
    "\001\000\004\017\046\001\001\000\004\011\062\001\001" +
    "\000\002\001\001\000\002\001\001\000\004\011\065\001" +
    "\001\000\002\001\001\000\002\001\001\000\006\003\070" +
    "\004\004\001\001\000\002\001\001\000\002\001\001\000" +
    "\002\001\001\000\002\001\001\000\004\011\076\001\001" +
    "\000\002\001\001\000\002\001\001\000\012\014\100\016" +
    "\027\017\036\020\034\001\001\000\004\017\046\001\001" +
    "\000\002\001\001\000\002\001\001\000\002\001\001\000" +
    "\002\001\001\000\002\001\001\000\002\001\001\000\002" +
    "\001\001\000\002\001\001\000\002\001\001\000\002\001" +
    "\001\000\002\001\001\000\002\001\001\000\002\001\001" +
    "\000\002\001\001" });

  /** Access to <code>reduce_goto</code> table. */
  public short[][] reduce_table() {return _reduce_table;}

  /** Instance of action encapsulation class. */
  protected CUP$PL0Parser$actions action_obj;

  /** Action encapsulation object initializer. */
  protected void init_actions()
    {
      action_obj = new CUP$PL0Parser$actions(this);
    }

  /** Invoke a user supplied parse action. */
  public java_cup.runtime.Symbol do_action(
    int                        act_num,
    java_cup.runtime.lr_parser parser,
    java.util.Stack            stack,
    int                        top)
    throws java.lang.Exception
  {
    /* call code in generated class */
    return action_obj.CUP$PL0Parser$do_action(act_num, parser, stack, top);
  }

  /** Indicates start state. */
  public int start_state() {return 0;}
  /** Indicates start production. */
  public int start_production() {return 0;}

  /** <code>EOF</code> Symbol index. */
  public int EOF_sym() {return 0;}

  /** <code>error</code> Symbol index. */
  public int error_sym() {return 1;}

}

/** Cup generated class to encapsulate user supplied action code.*/
class CUP$PL0Parser$actions {
  private final PL0Parser parser;

  /** Constructor */
  CUP$PL0Parser$actions(PL0Parser parser) {
    this.parser = parser;
  }

  /** Method with the actual generated action code. */
  public final java_cup.runtime.Symbol CUP$PL0Parser$do_action(
    int                        CUP$PL0Parser$act_num,
    java_cup.runtime.lr_parser CUP$PL0Parser$parser,
    java.util.Stack            CUP$PL0Parser$stack,
    int                        CUP$PL0Parser$top)
    throws java.lang.Exception
    {
      /* Symbol object for return from actions */
      java_cup.runtime.Symbol CUP$PL0Parser$result;

      /* select the action based on the action number */
      switch (CUP$PL0Parser$act_num)
        {
          /*. . . . . . . . . . . . . . . . . . . .*/
          case 40: // factor ::= LPAREN expression RPAREN 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("factor",14, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 39: // factor ::= INTEGER 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("factor",14, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 38: // factor ::= ID 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("factor",14, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 37: // multiplyingOperator ::= SLASH 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("multiplyingOperator",15, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 36: // multiplyingOperator ::= TIMES 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("multiplyingOperator",15, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 35: // term ::= term multiplyingOperator factor 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("term",12, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 34: // term ::= factor 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("term",12, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 33: // addingOperator ::= MINUS 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("addingOperator",13, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 32: // addingOperator ::= PLUS 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("addingOperator",13, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 31: // expression ::= expression addingOperator term 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("expression",10, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 30: // expression ::= addingOperator term 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("expression",10, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 29: // expression ::= term 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("expression",10, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 28: // relation ::= GE 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("relation",11, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 27: // relation ::= LE 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("relation",11, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 26: // relation ::= GT 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("relation",11, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 25: // relation ::= LT 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("relation",11, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 24: // relation ::= NE 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("relation",11, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 23: // relation ::= EQ 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("relation",11, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 22: // condition ::= expression relation expression 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("condition",9, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 21: // condition ::= ODD expression 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("condition",9, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 20: // statementList ::= statementList SEMICOLON statement 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statementList",8, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 19: // statementList ::= statement 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statementList",8, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 18: // statement ::= 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statement",7, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 17: // statement ::= WHILE condition DO statement 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statement",7, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-3)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 16: // statement ::= IF condition THEN statement 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statement",7, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-3)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 15: // statement ::= BEGIN statementList END 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statement",7, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 14: // statement ::= CALL ID 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statement",7, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 13: // statement ::= ID ASSIGN expression 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("statement",7, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 12: // procDecl ::= 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("procDecl",6, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 11: // procDecl ::= procDecl PROC ID SEMICOLON block SEMICOLON 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("procDecl",6, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-5)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 10: // identList ::= identList COMMA ID 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("identList",5, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 9: // identList ::= ID 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("identList",5, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 8: // varDecl ::= 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("varDecl",4, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 7: // varDecl ::= VAR identList SEMICOLON 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("varDecl",4, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 6: // constAssignmentList ::= constAssignmentList COMMA ID EQ INTEGER 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("constAssignmentList",3, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-4)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 5: // constAssignmentList ::= ID EQ INTEGER 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("constAssignmentList",3, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 4: // constDecl ::= 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("constDecl",2, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 3: // constDecl ::= CONST constAssignmentList SEMICOLON 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("constDecl",2, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-2)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 2: // block ::= constDecl varDecl procDecl statement 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("block",1, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-3)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 1: // program ::= block PERIOD 
            {
              Object RESULT =null;

              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("program",0, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          return CUP$PL0Parser$result;

          /*. . . . . . . . . . . . . . . . . . . .*/
          case 0: // $START ::= program EOF 
            {
              Object RESULT =null;
		int start_valleft = ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)).left;
		int start_valright = ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)).right;
		Object start_val = (Object)((java_cup.runtime.Symbol) CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)).value;
		RESULT = start_val;
              CUP$PL0Parser$result = parser.getSymbolFactory().newSymbol("$START",0, ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.elementAt(CUP$PL0Parser$top-1)), ((java_cup.runtime.Symbol)CUP$PL0Parser$stack.peek()), RESULT);
            }
          /* ACCEPT */
          CUP$PL0Parser$parser.done_parsing();
          return CUP$PL0Parser$result;

          /* . . . . . .*/
          default:
            throw new Exception(
               "Invalid action number found in internal parse table");

        }
    }
}

