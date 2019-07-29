%{
int token( int );
%}
DIGITO  [0-9]
LETRA   [A-Za-z_]
INT     {DIGITO}+
DOUBLE  {DIGITO}+("."{DIGITO}+)?
ID      {LETRA}({LETRA}|{DIGITO})*
STR     ("\""([^"]|\\\")*"\"")
STR2     ("\'"([^'])"\'")


%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	   { linha++; coluna = 1; }

{INT} 	   { return token( CINT ); }
{DOUBLE}   { return token( CDOUBLE ); }
{STR}      { return token( TK_STR ); }
{STR2}     { return token( TK_STR2 ); }
"true"     { return token( TK_BOOL ); }
"false"    { return token( TK_BOOL ); }
"int"	     { return token( TK_VAR_INT ); }
"real"     { return token( TK_VAR_REAL ); }
"char"     { return token( TK_VAR_CHAR ); }
"string"   { return token( TK_VAR_STRING ); }
"boolean"  { return token( TK_VAR_BOOL ); }
"console"  { return token( TK_CONSOLE ); }
">>"       { return token( TK_SHIFTR ); }
"<<"       { return token( TK_SHIFTL ); }
"for"      { return token( TK_FOR ); }
"in"       { return token( TK_IN ); }
".."       { return token( TK_2PT ); }
"if"       { return token( TK_IF ); }
"then"     { return token( TK_THEN ); }
"else"     { return token( TK_ELSE ); }
"endl"     { return token( TK_ENDL );}
"begin"    { return token( TK_BEGIN );}
"end"      { return token( TK_END );}
"and"      { return token( TK_AND );}
"or"       { return token( TK_OR );}
"not"      { return token( TK_NOT );}


{ID}       { return token( TK_ID ); }

.          { return token( *yytext ); }

%%

int token( int tk ) {
 yylval.v = yytext;
 coluna += strlen(yytext);
 return tk;

}
