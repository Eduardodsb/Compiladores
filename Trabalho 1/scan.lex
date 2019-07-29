%{ // Código em C/C++
#include <stdio.h>
#include <string>

using namespace std;

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _COMENTARIO };

%}

/* Coloque aqui definições regulares */
DIGITOS	[0-9]
LETRAS	[A-Za-z_]
CARACTERES_COMENTARIO [A-Za-zÀ-Ā!-)+-.:-@[-`{-¿]
CARACTERES_STRING [!#-\[\]-Ā]
WS	[ \t\n]

ID	{LETRAS}({LETRAS}|{DIGITOS})*
FOR "for"
IF "if"
INT {DIGITOS}+
FLOAT {INT}("."{INT})?([Ee]("+"|"-")?{INT})?
MAIG ">="
MEIG "<="
IG "=="
DIF "!="
STRING "\""(({CARACTERES_STRING}|{WS}|{DIGITOS})*|("\\""\"")*|("\"""\"")*|("\\")*)*"\""
COMENTARIO "/*"{A}"*/"|"/*"{B}"*/"|"/*"{C}"*/"|"/*"({A}|{B})*"*/"|"/*"({A}|({B}({CARACTERES_COMENTARIO}|{WS}|{DIGITOS})+)|({C}({CARACTERES_COMENTARIO}|{WS}|{DIGITOS})+))*"*/"
A (({CARACTERES_COMENTARIO}|{WS}|{DIGITOS})*|"/*")*
B (({CARACTERES_COMENTARIO}|{WS}|{DIGITOS})*|("*")*)*
C (({CARACTERES_COMENTARIO}|{WS}|{DIGITOS})*|("/")*)*

%%
  /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	{ /* ignora espaços, tabs e '\n' */ }
{FOR} {return _FOR;}
{IF}	{return _IF;}
{MAIG} {return _MAIG;}
{MEIG} {return _MEIG;}
{IG} {return _IG;}
{DIF} {return _DIF;}
{ID} {return _ID;}
{INT} {return _INT;}
{FLOAT} {return _FLOAT;}
{STRING} {return _STRING;}
{COMENTARIO} {return _COMENTARIO;}
. {return *yytext; /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */
int main() {
  int token = 0;

  while( (token = yylex()) != EOF )
    printf( "Token: %d %s\n", token, yytext );

  return 0;
}
