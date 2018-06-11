import java_cup . runtime . *;
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
":"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, :)", Symbol . COLON); }
"."		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, .)", Symbol . PERIOD); }
","		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ,)", Symbol . COMMA); }
"&&"	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, &&)", Symbol . AND); }
"//"	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, //)", Symbol . COMMENT); }
"|"	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, |)", Symbol . BAR); }
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
"!="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, !=)", Symbol . NE); }
"{"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, {)", Symbol . LCURLY); }
"}"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, })", Symbol . RCURLY); }
"["		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, [)", Symbol . LSQUARE); }
"]"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, ])", Symbol . RSQUARE); }
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
":="	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, :=)", Symbol . ASSIGN); }
"_"		{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, _)", Symbol . UNDERSCORE); }
import	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, import)", Symbol . IMPORT); }
public	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, public)", Symbol . PUBLIC); }
static	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, static)", Symbol . STATIC); }
void	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, void)", Symbol . VOID); }
main	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, main)", Symbol . MAIN); }
int		{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, int)", Symbol . INT); }
String	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, String)", Symbol . STRING); }
args	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, args)", Symbol . ARGS); }
new		{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, new)", Symbol . NEW); }
System	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, System)", Symbol . SYSTEM); }
out		{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, out)", Symbol . OUT); }
println	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, println)", Symbol . PRINTLN); }
return	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, return)", Symbol . RETURN); }
Scanner	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, Scanner)", Symbol . SCANNER); }
nextInt	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, nextInt)", Symbol . NEXTINT); }
facto	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, facto)", Symbol . FACTO); }
initialize	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, initialize)", Symbol . INITIALIZE); }
String	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, String)", Symbol . STRING); }
this	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, this)", Symbol . THIS); }
boolean	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, boolean)", Symbol . BOOLEAN); }
else	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, else)", Symbol . ELSE); }
in		{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, in)", Symbol . IN); }
class	{ echo ();
				  return symbolFactory .
					newSymbol ("(keyword, class)", Symbol . CLASS); }
begin	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, begin)", Symbol . BEGIN); }
call	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, end)", Symbol . CALL); }
const	{ echo (); 
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
