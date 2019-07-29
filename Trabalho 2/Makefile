all: gera_listas entrada.cc
	./gera_listas < entrada.cc > saida.cc

lex.yy.c: gera_listas.lex
	lex gera_listas.lex

y.tab.c: gera_listas.y
	yacc gera_listas.y

gera_listas: lex.yy.c y.tab.c
	g++ -o gera_listas y.tab.c -ll
