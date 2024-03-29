%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define YYSTYPE Atributos

int linha = 1;
int coluna = 1;

struct Atributos {
  string v;
  string c;

  int linha;
};

struct Lista {
  bool sublista;
  string valorString;
  Lista* valorSublista;
  Lista* proximo;
};

int yylex();
int yyparse();
void yyerror(const char *);

string geraNo( string pi, string valor, string sublista, string sub ) ;
string geraNomeVar();

int nVar = 0;

%}

%start S
%token TK_CINT TK_CDOUBLE TK_ID

%%

S : L { cout << "#include <string>\n\n"
		        "using namespace std;\n\n"
                "struct Lista {\n"
		        "  bool sublista;\n"
		        "  string valorString;\n"
		        "  Lista* valorSublista;\n"
		        "  Lista* proximo;\n"
		        "};\n\n"
		        "Lista* geraLista() {\n"
                "  Lista *p0";
        for( int i = 1; i < nVar; i++ )
            cout << ", *p" << i;
        cout << ";\n\n";
        cout << $1.c
             << "  return " + $1.v + ";\n"
                "}"
             << endl; }
  ;

L : A ',' L	{ $$.c = $1.c + "\n" + $3.c
                       + "  " + $1.v + "->proximo = " + $3.v + ";\n\n";
                  $$.v = $1.v; }
  | A		{ $$.c = $1.c + "\n" +
                       + "  " + $1.v + "->proximo = nullptr;\n\n"; }
  ;

A : TK_ID    	{ $$.v = geraNomeVar(); $$.c = geraNo( $$.v, $1.v,"false", "nullptr" );}
  | TK_CINT	{ $$.v = geraNomeVar(); $$.c = geraNo( $$.v, $1.v,"false", "nullptr" );}
  | TK_CDOUBLE	{ $$.v = geraNomeVar(); $$.c = geraNo( $$.v, $1.v,"false", "nullptr" );}
  | '(' B ')' {$$.v = geraNomeVar(); $$.c =  $2.c +"\n"+ geraNo( $$.v, "", "true", $2.v ) +"\n";}
  | {$$.v = "nullptr"; $$.c = "";}
  ;

B : A ',' B { $$.c = $1.c + "\n" + $3.c
              + "  " + $1.v + "->proximo= " +  $3.v + ";\n\n";
                $$.v = $1.v;}
  | A { $$.c = $1.c + "\n"; $$.v = $1.v; }
  ;
%%

#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st );
   printf( "Linha %d, coluna %d, proximo a: %s\n", linha, coluna, yytext );
   exit( 0 );
}

string geraNomeVar() {
  char buf[20] = "";

  sprintf( buf, "p%d", nVar++ );

  return buf;
}

string geraNo( string pi, string valor, string sublista, string sub ) {
 return "  " + pi + " = new Lista;\n"
        "  " + pi + "->sublista = " + sublista + ";\n"
        "  " + pi + "->valorString = \"" + valor + "\";\n"
        "  " + pi + "->valorSublista = "+ sub +";\n";
}

int main( int argc, char* argv[] )
{
  yyparse();
}
