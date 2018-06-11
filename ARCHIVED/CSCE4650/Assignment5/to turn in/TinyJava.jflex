import java_cup.runtime.SymbolFactory;
%%
%{
  private SymbolFactory symbolFactory;

  public TinyJavaLexer (java . io . InputStream input, SymbolFactory sf) {
    this (input);
    symbolFactory = sf;
  }

  private void echo () { System . out . print (yytext ()); }

  public int position () { return yycolumn; }
%}

%class    TinyJavaLexer
%unicode
%line
%column
%cupsym Symbol
%cup
%eofval{
  { return symbolFactory .  newSymbol ("EOF", Symbol . EOF); }
%eofval}

Identifier = [:letter:]("_"?([:letter:] | [:digit:]))*
Integer    = [:digit:] [:digit:]*
Comment    = "//".*

%%
[ \t\n]		{ echo (); }
{Comment}	{ echo (); }
";"		{ echo (); return symbolFactory . 
                    newSymbol ("(punctuation, ;)", Symbol . SEMICOLON); }
"."		{ echo (); return symbolFactory . 
                    newSymbol ("(punctuation, .)", Symbol . DOT); }
","		{ echo (); return symbolFactory . 
                    newSymbol ("(punctuation, ,)", Symbol . COMMA); }
"{"             { echo (); return symbolFactory . 
                    newSymbol ("(punctuation, {)", Symbol . LBRACE); }
"}"             { echo (); return symbolFactory . 
                    newSymbol ("(punctuation, })", Symbol . RBRACE); }
"["             { echo (); return symbolFactory . 
                    newSymbol ("(operator, [)", Symbol . LBRACK); }
"]"             { echo (); return symbolFactory . 
                    newSymbol ("(operator, ])", Symbol . RBRACK); }
"("             { echo (); return symbolFactory . 
                    newSymbol ("(operator, ()", Symbol . LPAREN); }
")"             { echo (); return symbolFactory . 
                    newSymbol ("(operator, ))", Symbol . RPAREN); }
"!"             { echo (); return symbolFactory . 
                    newSymbol ("(operator, !)", Symbol . NOT); }
"&&"            { echo (); return symbolFactory . 
                    newSymbol ("(operator, &&)", Symbol . AND); }
"||"            { echo (); return symbolFactory . 
                    newSymbol ("(operator, ||)", Symbol . OR); }
"<"		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, <)", Symbol . LT); }
"<="		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, <=)", Symbol . LE); }
">"		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, >)", Symbol . GT); }
">="		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, >=)", Symbol . GE); }
"=="		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, ==)", Symbol . EQ); }
"!="		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, !=)", Symbol . NE); }
"+"		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, +)", Symbol . PLUS); }
"-"		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, -)", Symbol . MINUS); }
"*"		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, *)", Symbol . TIMES); }
"/"		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, /)", Symbol . SLASH); }
"="		{ echo (); return symbolFactory . 
                    newSymbol ("(operator, =)", Symbol . ASSIGN); }
args            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, args)", Symbol . ARGS); }
boolean         { echo (); return symbolFactory . 
                    newSymbol ("(keyword, boolean)", Symbol . BOOLEAN); }
class           { echo (); return symbolFactory . 
                    newSymbol ("(keyword, class)", Symbol . CLASS); }
else            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, else)", Symbol . ELSE); }
false           { echo (); return symbolFactory . 
                    newSymbol ("(keyword, false)", Symbol . FALSE); }
if		{ echo (); return symbolFactory . 
                    newSymbol ("(keyword, if)", Symbol . IF); }
in		{ echo (); return symbolFactory . 
                    newSymbol ("(keyword, in)", Symbol . IN); }
int             { echo (); return symbolFactory . 
                    newSymbol ("(keyword, int)", Symbol . INT); }
import          { echo (); return symbolFactory . 
                    newSymbol ("(keyword, import)", Symbol . IMPORT); }
java            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, java)", Symbol . JAVA); }
main            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, main)", Symbol . MAIN); }
new             { echo (); return symbolFactory . 
                    newSymbol ("(keyword, new)", Symbol . NEW); }
nextInt         { echo (); return symbolFactory . 
                    newSymbol ("(keyword, nextInt)", Symbol . NEXTINT); }
out             { echo (); return symbolFactory . 
                    newSymbol ("(keyword, out)", Symbol . OUT); }
println         { echo (); return symbolFactory . 
                    newSymbol ("(keyword, println)", Symbol . PRINTLN); }
public          { echo (); return symbolFactory . 
                    newSymbol ("(keyword, public)", Symbol . PUBLIC); }
return          { echo (); return symbolFactory . 
                    newSymbol ("(keyword, return)", Symbol . RETURN); }
Scanner         { echo (); return symbolFactory . 
                    newSymbol ("(keyword, Scanner)", Symbol . SCANNER); }
static          { echo (); return symbolFactory . 
                    newSymbol ("(keyword, static)", Symbol . STATIC); }
String          { echo (); return symbolFactory . 
                    newSymbol ("(keyword, String)", Symbol . STRING); }
System          { echo (); return symbolFactory . 
                    newSymbol ("(keyword, System)", Symbol . SYSTEM); }
this            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, this)", Symbol . THIS); }
true            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, true)", Symbol . TRUE); }
util            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, util)", Symbol . UTIL); }
void            { echo (); return symbolFactory . 
                    newSymbol ("(keyword, void)", Symbol . VOID); }
while		{ echo (); return symbolFactory . 
                    newSymbol ("(keyword, while)", Symbol . WHILE); }
{Integer}	{ echo (); return symbolFactory . 
                    newSymbol ("(integer, " + yytext () + ")", 
                      Symbol . INTEGER, yytext ()); }
{Identifier}	{ echo (); return symbolFactory . 
                    newSymbol ("(id, " + yytext () + ")", Symbol . ID, 
                      yytext ()); }
.		{ echo (); ErrorMessage . print (yychar, "Illegal character"); }
