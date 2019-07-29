%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define YYSTYPE Atributos

int linha = 1;
int coluna = 1;
string variaveis = "int ";

struct Atributos {
  string v;
  string c;
  int linha;
};

int yylex();
int yyparse();
void yyerror(const char *);

string geraNomeVar();
string geraGoTo();
int nVar = 0;
int nGoTo = 0;

%}

%start S
%token CINT CDOUBLE TK_ID TK_VAR TK_CONSOLE TK_SHIFTR TK_SHIFTL
%token TK_FOR TK_IN TK_2PT TK_IF TK_THEN TK_ELSE TK_ENDL TK_STR
%token TK_BEGIN TK_END

%left '<' '>' '='
%left '&' '|'
%left '!'
%left '+' '-'
%left '*' '/' '%'

%%

S : CMDS
    { variaveis[variaveis.size()-1] = ';';
      cout << "#include<stdio.h>\n"
              "#include <iostream>\n"
              "using namespace std;\n\n"
              "int main(){\n" + variaveis + "\n"
               + $1.c + "\n"
              "return 0;\n}" << endl; }
  | DECLVAR ';' S
  ;

CMDS : CMDS CMD  { $$.c = $1.c + $2.c; }
     | CMD
     ;

CMD : ENTRADA ';'
    | SAIDA ';'
    | ATR ';'
    | FOR
    | IF
    ;

DECLVAR : TK_VAR VARS
        { variaveis = variaveis + " " + $2.c + ","; }
        |
        ;

VARS : VARS ',' VAR  { $$.c = $1.c + ", " + $3.c; }
     | VAR
     ;

VAR : TK_ID '[' CINT ']'
      { $$.c = $1.v + "[" + $3.v + "]"; }
    | TK_ID
      { $$.c = $1.v; }
    ;

ENTRADA : TK_CONSOLE PARAMETRO_ENTRADA
          {$$.c = $2.c;}
          ;

PARAMETRO_ENTRADA : TK_SHIFTR TK_ID PARAMETRO_ENTRADA
                    { $$.c = "cin >> " + $2.v + ";\n" + $3.c; }
                  | TK_SHIFTR TK_ID '[' E ']' PARAMETRO_ENTRADA
                  { $$.v = geraNomeVar();
                    $$.c = $4.c
                         + "cin >> " + $$.v + ";\n"
                         + $2.v + "[" + $4.v + "] = " + $$.v + ";\n" + $6.c; }
                  | TK_SHIFTR TK_ID
                    { $$.c = "cin >> " + $2.v + ";\n"; }
                  | TK_SHIFTR TK_ID '[' E ']'
                  { $$.v = geraNomeVar();
                    $$.c = $4.c
                         + "cin >> " + $$.v + ";\n"
                         + $2.v + "[" + $4.v + "] = " + $$.v + ";\n"; }
                   ;

SAIDA : TK_CONSOLE PARAMETRO_SAIDA
        {$$.c = $2.c;}
        ;


PARAMETRO_SAIDA : TK_SHIFTL E PARAMETRO_SAIDA
                  { $$.c = $2.c + "cout << " + $2.v + ";\n" + $3.c; }
                | TK_SHIFTL TK_ENDL PARAMETRO_SAIDA
                  { $$.c = "cout << endl;\n" + $3.c; }
                | TK_SHIFTL TK_STR PARAMETRO_SAIDA
                  { $$.c = "cout << " + $2.v + ";\n" + $3.c; }
                | TK_SHIFTL E
                  { $$.c = $2.c + "cout << " + $2.v + ";\n"; }
                | TK_SHIFTL TK_ENDL
                  { $$.c = "cout << endl;\n"; }
                | TK_SHIFTL TK_STR
                  { $$.c = "cout << " + $2.v + ";\n"; }
                ;

FOR : TK_FOR TK_ID TK_IN '[' E TK_2PT E ']' COMANDOS_1
      {  string cond = geraNomeVar(); string label = geraGoTo(); string label2 = geraGoTo();

         $$.c = $5.c + $7.c
              + $2.v + " = " + $5.v + ";\n"
              + label + ":\n" + cond + " = " + $2.v + " > " + $7.v + ";\n"
              + "if( " + cond + ") goto " + label2 + ";\n"
              + $9.c
              + $2.v + " = " + $2.v + " + 1;\n"
              + "goto "+ label + ";\n"
              + label2 + ":\n";
      }
    |  TK_FOR TK_ID TK_IN '[' E TK_2PT E ']' TK_BEGIN COMANDOS_2 TK_END ';'
        {  string cond = geraNomeVar(); string label = geraGoTo(); string label2 = geraGoTo();

           $$.c = $5.c + $7.c
                + $2.v + " = " + $5.v + ";\n"
                + label + ":\n" + cond + " = " + $2.v + " > " + $7.v + ";\n"
                + "if( " + cond + ") goto " + label2 + ";\n"
                + $10.c
                + $2.v + " = " + $2.v + " + 1;\n"
                + "goto "+ label + ";\n"
                + label2 + ":\n";
        }
    ;


IF : TK_IF E TK_THEN TK_BEGIN COMANDOS_2 TK_END ';'
     {string label = geraGoTo(); string cond = geraNomeVar();
      $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $5.c + "\n" + label + ":\n";}
   | TK_IF E TK_THEN TK_BEGIN COMANDOS_2 TK_END TK_ELSE TK_BEGIN COMANDOS_2 TK_END ';'
     {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar();
      $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $5.c + "\n" + label + ":\n"+
                    "if(" + $2.v + ") goto "+ label2 + ";\n"+ $9.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1
        {string label = geraGoTo(); string cond = geraNomeVar();
         $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1 TK_ELSE COMANDOS_1
     {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar();
      $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n"+
                    "if(" + $2.v + ") goto "+ label2 + ";\n"+ $6.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN TK_BEGIN COMANDOS_2 TK_END TK_ELSE COMANDOS_1
     {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar();
           $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n"+
                         "if(" + $2.v + ") goto "+ label2 + ";\n"+ $8.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1 TK_ELSE TK_BEGIN COMANDOS_2 TK_END ';'
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar();
          $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n"+
                   "if(" + $2.v + ") goto "+ label2 + ";\n"+ $7.c + "\n" + label2 + ":\n";}
   ;

COMANDOS_1: ENTRADA ';'
          | SAIDA ';'
          | ATR ';'
          ;

COMANDOS_2: CMDS
         |
         ;

ATR : TK_ID '=' E
      { $$.v = $3.v;
        $$.c = $3.c + $1.v + " = " + $3.v + ";\n";
      }
    | TK_ID '[' E ']' '=' E
      { $$.c = $3.c + $6.c
             + $1.v + "[" + $3.v + "] = " + $6.v + ";\n";
        $$.v = $6.v;
      }
    ;

E : E '+' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + "+" + $3.v + ";\n";
    }
  | E '-' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + "-" + $3.v + ";\n";
    }
  | E '*' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + "*" + $3.v + ";\n";
    }
  | E '/' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + "/" + $3.v + ";\n";
    }
  | E '%' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + '%' + $3.v + ";\n";
    }
  | E '<' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + "<" + $3.v + ";\n";
    }
  | E '>' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $3.c + $$.v + " = " + $1.v + ">" + $3.v + ";\n";
    }
  | E '<''=' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $4.c + $$.v + " = " + $1.v + "<=" + $4.v + ";\n";
    }
  | E '>''=' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $4.c + $$.v + " = " + $1.v + ">=" + $4.v + ";\n";
    }
  | E '=''=' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $4.c + $$.v + " = " + $1.v + "==" + $4.v + ";\n";
    }
  | E '!''=' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $4.c + $$.v + " = " + $1.v + "!=" + $4.v + ";\n";
    }
  | E '&''&' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $4.c + $$.v + " = " + $1.v + "&&" + $4.v + ";\n";
    }
  | E '|''|' E
    { $$.v = geraNomeVar();
      $$.c = $1.c + $4.c + $$.v + " = " + $1.v + "||" + $4.v + ";\n";
    }
  | '!' E
    { $$.v = geraNomeVar();
      $$.c = $2.c + $$.v + " = " + "!" + $2.v + ";\n";
    }
  | V
  ;


V : TK_ID '[' E ']'
    { $$.v = geraNomeVar();
      $$.c = $3.c + $$.v + " = " + $1.v + "[" + $3.v + "];\n";
    }
  | TK_ID     { $$.c = ""; $$.v = $1.v; }
  | CINT      { $$.c = ""; $$.v = $1.v; }
  | '(' E ')' { $$ = $2; }
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

  sprintf( buf, "t%d", nVar++ );

  variaveis = variaveis + " " + buf + ",";

  return buf;
}

string geraGoTo() {
  char buf[20] = "";

  sprintf( buf, "Local%d", nGoTo++ );

  return buf;
}

int main( int argc, char* st[]) {
  yyparse();

  return 0;
}
