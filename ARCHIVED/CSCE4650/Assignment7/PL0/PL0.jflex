import java_cup.runtime.SymbolFactory;
%%

%class PL0Lexer
%unicode
%line
%column
%cupsym Symbol
%cup
%eofval{
  return symbolFactory . newSymbol ("EOF", Symbol . EOF);
%eofval}

%{
  private SymbolFactory symbolFactory;

  public PL0Lexer (java . io . InputStream input, SymbolFactory sf) {
    this (input);
    symbolFactory = sf;
  }

  private void echo () { System . out . print (yytext ()); }

  public int position () { return yycolumn; }
%}

Identifier = [:letter:] ([:letter:] | [:digit:])*
Integer    = [:digit:] [:digit:]*

%%
[ \t\n]		{ echo (); }
";"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ;)", Symbol . SEMICOLON); }
"."		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, .)", Symbol . PERIOD); }
","		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ,)", Symbol . COMMA); }
"<"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, <)", Symbol . LT); }
"<="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, <=)", Symbol . LE); }
">"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, >)", Symbol . GT); }
">="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, >=)", Symbol . GE); }
"="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, =)", Symbol . EQ); }
"<>"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, <>)", Symbol . NE); }
"("		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, ()", Symbol . LPAREN); }
")"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, ))", Symbol . RPAREN); }
"+"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, +)", Symbol . PLUS); }
"-"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, -)", Symbol . MINUS); }
"*"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, *)", Symbol . TIMES); }
"/"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, /)", Symbol . SLASH); }
":="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, :=)", Symbol . ASSIGN); }
begin		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, begin)", Symbol . BEGIN); }
call		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, end)", Symbol . CALL); }
const		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, const)", Symbol . CONST); }
do		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, do)", Symbol . DO); }
end		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, end)", Symbol . END); }
if		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, if)", Symbol . IF); }
odd		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, odd)", Symbol . ODD); }
procedure	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, procedure)", Symbol . PROC); }
then		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, then)", Symbol . THEN); }
var		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, var)", Symbol . VAR); }
while		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, while)", Symbol . WHILE); }
{Integer}	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(integer, " + yytext () + ")", 
                      Symbol . INTEGER, yytext ()); }
{Identifier}	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(identifier, " + yytext () + ")", 
                      Symbol . ID, yytext ()); }
.		{ echo (); ErrorMessage . print (yychar, "Illegal character"); }
