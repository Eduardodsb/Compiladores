%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define YYSTYPE Atributos

int linha = 1;
int coluna = 1;

typedef string Tipo;

struct Atributos {
  string v = "";
  string c = "";
  Tipo t = "";
  vector<Tipo> temp;
  int linha;
};

map<string,Tipo> tsVar;
map<string,Tipo> relacaoTipos ={
{"I", "int"}, {"S", "string"}, {"C", "char"}, {"R", "real"}, {"B", "boolean"}
};
map<string,Tipo> relacaoOperadores ={
{"+","+"},{"-","-"},{"*","*"},{"/","/"},{"%","%"},
{"<","<"},{">",">"},{"<=","<="},{">=",">="},{"==","=="},{"<>","!="},
{"and","&&"},{"or","||"},{"not","!"},
};
map<string,Tipo> resOpr = {
{ "+II", "I" }, { "+IR", "R" }, { "+RI", "R" }, { "+RR", "R" },
{ "+CC", "S" }, { "+CS", "S" }, { "+SC", "S" }, { "+SS", "S" },
{ "+CI", "I" }, { "+IC", "I" }, { "+SS", "S" },

{ "-II", "I" }, { "-IR", "R" }, { "-RI", "R" }, { "-RR", "R" },
{ "-CC", "S" }, { "-CS", "S" }, { "-SC", "S" }, { "-SS", "S" },
{ "-CI", "I" }, { "-IC", "I" },

{ "*II", "I" }, { "*IR", "R" }, { "*RI", "R" }, { "*RR", "R" },
{ "*CI", "I" }, { "*IC", "I" },

{ "/II", "I" }, { "/IR", "R" }, { "/RI", "R" }, { "/RR", "R" },
{ "/CI", "I" }, { "/IC", "I" },

{ "%II", "I" }, { "%IR", "R" }, { "'%RI", "R" }, { "%RR", "R" },
{ "%CI", "I" }, { "%IC", "I" },

{ ">II", "B" }, { ">RR", "B" }, { ">CC", "B" }, { ">SS", "B" }, { ">BB", "B" },
{ ">IR", "B" }, { ">RI", "B" }, { ">IC", "B" }, { ">CI", "B" }, { ">SC", "B" },
{ ">CS", "B" }, { ">IB", "B" }, { ">BI", "B" },

{ "<II", "B" }, { "<RR", "B" }, { "<CC", "B" }, { "<SS", "B" }, { "<BB", "B" },
{ "<IR", "B" }, { "<RI", "B" }, { "<IC", "B" }, { "<CI", "B" }, { "<SC", "B" },
{ "<CS", "B" }, { "<IB", "B" }, { "<BI", "B" },

{ ">=II", "B" }, { ">=RR", "B" }, { ">=CC", "B" }, { ">=SS", "B" }, { ">=BB", "B" },
{ ">=IR", "B" }, { ">=RI", "B" }, { ">=IC", "B" }, { ">=CI", "B" }, { ">=SC", "B" },
{ ">=CS", "B" }, { ">=IB", "B" }, { ">=BI", "B" },

{ "<=II", "B" }, { "<=RR", "B" }, { "<=CC", "B" }, { "<=SS", "B" }, { "<=BB", "B" },
{ "<=IR", "B" }, { "<=RI", "B" }, { "<=IC", "B" }, { "<=CI", "B" }, { "<=SC", "B" },
{ "<=CS", "B" }, { "<=IB", "B" }, { "<=BI", "B" },

{ "==II", "B" }, { "==RR", "B" }, { "==CC", "B" }, { "==SS", "B" }, { "==BB", "B" },
{ "==IR", "B" }, { "==RI", "B" }, { "==IC", "B" }, { "==CI", "B" }, { "==SC", "B" },
{ "==CS", "B" }, { "==IB", "B" }, { "==BI", "B" },

{ "<>II", "B" }, { "<>RR", "B" }, { "<>CC", "B" }, { "<>SS", "B" }, { "<>BB", "B" },
{ "<>IR", "B" }, { "<>RI", "B" }, { "<>IC", "B" }, { "<>CI", "B" }, { "<>SC", "B" },
{ "<>CS", "B" }, { "<>IB", "B" }, { "<>BI", "B" },

{ "andBB", "B" }, { "andII", "B" }, { "andIB", "B" }, { "andBI", "B" }, { "andRB", "B" }, { "andBR", "B" },

{ "orBB", "B" }, { "orII", "B" }, { "orIB", "B" }, { "orBI", "B" }, { "orRB", "B" }, { "orBR", "B" },

{ "notB", "B" }, { "notI", "B" },
};

int yylex();
int yyparse();
void yyerror(const char *);

string geraNomeVar( Tipo t );
string declaraTemps();
Atributos geraCodigoOperador( Atributos a, string operador, Atributos b );
string geraGoTo();
void montaTabelaDeVariaveis(vector<Tipo> variaveis, Tipo tipo);
Tipo buscaTipoVar(string variavel);
string geraCodigoAtribuicao(Atributos ID, Atributos Exp);
map<Tipo,int> nVar;
int nGoTo = 0;

%}

%start S
%token CINT CDOUBLE TK_ID TK_STR TK_STR2 TK_BOOL TK_CONSOLE TK_SHIFTR TK_SHIFTL
%token TK_FOR TK_IN TK_2PT TK_IF TK_THEN TK_ELSE TK_ENDL
%token TK_BEGIN TK_END TK_AND TK_OR TK_NOT
%token TK_VAR_INT TK_VAR_REAL TK_VAR_CHAR TK_VAR_STRING TK_VAR_BOOL

%left TK_AND TK_OR
%left TK_NOT
%left '<' '>' '='
%left '+' '-'
%left '*' '/' '%'

%%

S : DECLVAR CMDS {cout << "#include<stdio.h>\n"
                    "#include <iostream>\n"
                    "#include <string.h>\n"
                    "using namespace std;\n\n"
                    "int main(){\n" + $1.c + declaraTemps() + "\n"
                     + $2.c + "\n"
                   "return 0;\n}" << endl;}
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

DECLVAR : TIPO VARS ';' DECLVAR
        { $$.c = $1.c + $2.c + ";\n" + $4.c; montaTabelaDeVariaveis($2.temp, $1.t);}
        | {$$.c = "";}
        | TK_VAR_STRING VARS2 ';' DECLVAR {$$.c = "char " + $2.c + ";\n" + $4.c;  montaTabelaDeVariaveis($2.temp, "S");}
        ;

VARS : VARS ',' VAR  { $$.c = $1.c + ", " + $3.c; $$.temp = $1.temp; $$.temp.push_back($3.temp[0]);}
     | VAR {$$.temp = $1.temp;}
     ;

VAR : TK_ID '[' CINT ']'
      { $$.c = $1.v + "[" + $3.v + "]"; $$.temp.push_back($1.v);}
    | TK_ID
      { $$.c = $1.v; $$.temp.push_back($1.v);}
    ;

TIPO: TK_VAR_INT {$$.c = "int "; $$.t = "I";}
    | TK_VAR_REAL {$$.c = "double "; $$.t = "R";}
    | TK_VAR_CHAR {$$.c = "char "; $$.t = "C";}
    | TK_VAR_BOOL {$$.c = "int "; $$.t = "B";}
    ;

VARS2: VARS2 ',' VAR2  { $$.c = $1.c + ", " + $3.c; $$.temp = $1.temp; $$.temp.push_back($3.temp[0]);}
     | VAR2 {$$.temp = $1.temp;}
     ;

VAR2: TK_ID '[' CINT ']'
      { $$.c = $1.v + "[" + $3.v + "]" + "[257]"; $$.temp.push_back($1.v);}
    | TK_ID
      { $$.c = $1.v + "[257]"; $$.temp.push_back($1.v);}

ENTRADA : TK_CONSOLE PARAMETRO_ENTRADA
          {$$.c = $2.c;}
          ;

PARAMETRO_ENTRADA : TK_SHIFTR TK_ID PARAMETRO_ENTRADA
                    { $$.c = "cin >> " + $2.v + ";\n" + $3.c; }
                  | TK_SHIFTR TK_ID '[' E ']' PARAMETRO_ENTRADA
                  { $$.v = geraNomeVar("I");
                    $$.c = $4.c
                         + "cin >> " + $$.v + ";\n"
                         + $2.v + "[" + $4.v + "] = " + $$.v + ";\n" + $6.c; }
                  | TK_SHIFTR TK_ID
                    { $$.c = "cin >> " + $2.v + ";\n"; }
                  | TK_SHIFTR TK_ID '[' E ']'
                  { $$.v = geraNomeVar("I");
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
                | TK_SHIFTL E
                  { $$.c = $2.c + "cout << " + $2.v + ";\n"; }
                | TK_SHIFTL TK_ENDL
                  { $$.c = "cout << endl;\n"; }
                ;

FOR : TK_FOR TK_ID TK_IN '[' E TK_2PT E ']' COMANDOS_1
      {  string cond = geraNomeVar("I"); string label = geraGoTo(); string label2 = geraGoTo();

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
        {  string cond = geraNomeVar("I");  string label = geraGoTo(); string label2 = geraGoTo();

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
     {string label = geraGoTo(); string cond = geraNomeVar("I");
      $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $5.c + "\n" + label + ":\n";}
   | TK_IF E TK_THEN TK_BEGIN COMANDOS_2 TK_END TK_ELSE TK_BEGIN COMANDOS_2 TK_END ';'
     {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
      $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $5.c + "\n" + label + ":\n"+
                    "if(" + $2.v + ") goto "+ label2 + ";\n"+ $9.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1
        {string label = geraGoTo(); string cond = geraNomeVar("I");
         $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1 TK_ELSE COMANDOS_1
     {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
      $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n"+
                    "if(" + $2.v + ") goto "+ label2 + ";\n"+ $6.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN TK_BEGIN COMANDOS_2 TK_END TK_ELSE COMANDOS_1
     {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
           $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n"+
                         "if(" + $2.v + ") goto "+ label2 + ";\n"+ $8.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1 TK_ELSE TK_BEGIN COMANDOS_2 TK_END ';'
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I");
          $$.c = $2.c + cond + " = !" + $2.v +";\nif(" + cond + ") goto " + label +";\n"+ $4.c + "\n" + label + ":\n"+
                   "if(" + $2.v + ") goto "+ label2 + ";\n"+ $7.c + "\n" + label2 + ":\n";}
   | TK_IF E TK_THEN COMANDOS_1 TK_ELSE TK_IF E TK_THEN COMANDOS_1
    {string label = geraGoTo(); string label2 = geraGoTo();string cond = geraNomeVar("I"); string cond2 = geraNomeVar("I");
         $$.c = $2.c + cond + " = !" + $2.v +";\n" + $7.c + cond2 + " = !" + $7.v +";\n" +
          "if(" + cond + ") goto " + label +";\n"+ $4.c + "\ngoto "+ label2 + ";\n" + label + ":\n"+
                  "if(" + cond2 + ") goto "+ label2 + ";\n"+ $9.c + "\n" + label2 + ":\n";}
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
        $$.c = $3.c + geraCodigoAtribuicao($1,$3);
      }
    | TK_ID '[' E ']' '=' E
      { $$.c = $3.c + $6.c
             + $1.v + "[" + $3.v + "] = " + $6.v + ";\n";
        $$.v = $6.v;
      }
    ;

E : E '+' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '-' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '*' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '/' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '%' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '<' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '>' E
    { $$ = geraCodigoOperador( $1, $2.v, $3 ); }
  | E '<''=' E
    { $$ = geraCodigoOperador( $1, $2.v + $3.v, $4 ); }
  | E '>''=' E
    { $$ = geraCodigoOperador( $1, $2.v + $3.v, $4 ); }
  | E '=''=' E
    { $$ = geraCodigoOperador( $1, $2.v + $3.v, $4 ); }
  | E '<''>' E
    { $$ = geraCodigoOperador( $1, $2.v + $3.v, $4 ); }
  | E TK_AND E
    { $$ = geraCodigoOperador( $1, "and", $3 ); }
  | E TK_OR E
    { $$ = geraCodigoOperador( $1, "or", $3 ); }
  | TK_NOT E
    {  Atributos a; a.t = ""; a.v = ""; a.c = ""; $$ = geraCodigoOperador( a, "not", $2 ); }
  | V
  ;


V : TK_ID '[' E ']'
    { $$.v = geraNomeVar($3.t);
      $$.c = $3.c + $$.v + " = " + $1.v + "[" + $3.v + "];\n";
    }
    | TK_ID     { $$.c = ""; $$.v = $1.v; $$.t = buscaTipoVar( $1.v ); }
    | CINT      { $$.c = ""; $$.v = $1.v; $$.t = "I"; }
    | CDOUBLE   { $$.c = ""; $$.v = $1.v; $$.t = "R"; }
    | TK_STR    { $$.c = ""; $$.v = $1.v; $$.t = "S"; }
    | TK_STR2   { $$.c = ""; $$.v = $1.v; $$.t = "C"; }
    | TK_BOOL   { $$.c = ""; $$.v = $1.v; $$.t = "B"; }
    | '(' E ')' { $$ = $2; }
    ;

%%

#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st );
   printf( "Linha %d, coluna %d, proximo a: %s\n", linha, coluna, yytext );
   exit( 0 );
}

Tipo buscaTipoOperacao( Tipo a, string operador, Tipo b ) {
  return resOpr[operador + a + b];
  // TODO: usar o find. Perda de performance de 1e-9 s
}

Atributos geraCodigoOperador( Atributos a, string operador, Atributos b ) {
  Atributos r;
  string tamString1, tamString2, atrA, atrB;
  atrA = a.v;
  atrB = b.v;

  r.t = buscaTipoOperacao( a.t, operador, b.t );
  if( r.t == "" ) {
    string temp = "Operacao '" + operador + "' inválida entre " + relacaoTipos[a.t] + " e " + relacaoTipos[b.t];
    yyerror( temp.c_str() );
  }

  r.v = geraNomeVar( r.t );
  if(((a.t == "S" && b.t == "S") || (a.t == "C" && b.t == "C") || (a.t == "S" && b.t == "C") || (a.t == "C" && b.t == "S")) && (operador == "+")){
    tamString1 = geraNomeVar("I");
    tamString2 = geraNomeVar("I");
    r.c = a.c + b.c;

    if(a.t == "C"){
      atrA = geraNomeVar("S");
      r.c += atrA + "[0] = " + a.v + ";\n";
/*      r.c += atrA + "[1] = " + "\'\\0\'" + ";\n";*/
      r.c += tamString1 + " = 1;";
    }else{
      r.c += tamString1 + " = strlen(" + a.v + ");\n";
    }

    if(b.t == "C"){
      atrB = geraNomeVar("S");
      r.c += atrB + "[0] = " + b.v + ";\n";
/*      r.c += atrB + "[1] = " + "\'\\0\'" + ";\n";*/
      r.c += tamString2 + " = 1;";
    }else{
      r.c += tamString2 + " = strlen(" + b.v + ");\n";
    }

    r.c += "strncpy("+ r.v + ",\"\",257);\n" + "strncpy("+ r.v +","+ atrA +","+ tamString1 +");\n" + "strncat("+ r.v + "," + atrB + ","+ tamString2 +");\n";

  }else if( ((a.t == "S" && b.t == "S") || (a.t == "C" && b.t == "C") || (a.t == "S" && b.t == "C") || (a.t == "C" && b.t == "S")) &&
  (operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "<>")){
    string temp;
    r.c = a.c + b.c;

    if(a.t == "C"){
      atrA = geraNomeVar("S");
      r.c += atrA + "[0] = " + a.v + ";\n";
    }

    if(b.t == "C"){
      atrB = geraNomeVar("S");
      r.c += atrB + "[0] = " + b.v + ";\n";
    }

    if(operador == "=="){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " == 0;\n";
    }
    if(operador == ">"){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " == 1;\n";
    }
    if(operador == "<"){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " < 0;\n";
    }
    if(operador == "<>"){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " != 0;\n";
    }
    if(operador == "<="){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " <= 0;\n";
    }
    if(operador == ">="){
      temp = geraNomeVar("I");
      r.c += temp + "= strcmp(" + atrA +","+ atrB + ");\n";
      r.c += r.v + " = "+ temp + " >= 0;\n";
    }

  }else{
    r.c = a.c + b.c +
          r.v + " = " + a.v + relacaoOperadores[operador] + b.v + ";\n";
  }
  return r;
}

string toString( int n ) {
  char buf[20] = "";

  sprintf( buf, "%d", n );

  return buf;
}

string geraNomeVar( Tipo t ) {
  return "temp_" + t + "_" + toString( nVar[t]++ );
}

string declaraTemps() {
  string res;

  for( auto p : nVar )
    for( int i = 0; i < p.second; i ++ ) {
      string nomeTipo;
      string string = "";
      if( p.first == "I" )
        nomeTipo = "int";
      else if( p.first == "R" )
        nomeTipo = "double";
      else if( p.first == "C" )
        nomeTipo = "char";
      else if( p.first == "S" ){
        nomeTipo = "char";
        string = "[257]";
      }else if( p.first == "B" )
        nomeTipo = "int";

      res += nomeTipo + " temp_" + p.first + "_" + toString( i ) + string + ";\n";
     }

  return res;
}


string geraGoTo() {
  char buf[20] = "";

  sprintf( buf, "Local%d", nGoTo++ );

  return buf;
}

void montaTabelaDeVariaveis(vector<Tipo> variaveis, Tipo tipo){
  for(int i = 0; i < variaveis.size(); i++){
    tsVar[variaveis[i]] = tipo;
  }
}

Tipo buscaTipoVar(string variavel ){
 return tsVar[variavel];
}

string geraCodigoAtribuicao(Atributos ID, Atributos Exp){
  string tamString;
  if(Exp.t == "S" && buscaTipoVar(ID.v) == "S"){
    tamString = geraNomeVar("I");
    return tamString + " = strlen(" +  Exp.v + ");\n" + "strncpy("+ ID.v + ",\"\",257);\n" + "strncpy(" + ID.v + "," + Exp.v + "," + tamString + ");\n";
  }
  return ID.v + " = " + Exp.v + ";\n";
}

int main( int argc, char* st[]) {
  yyparse();

  return 0;
}
