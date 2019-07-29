all: saida
	./saida

saida: codigo.cc
	g++ -o saida codigo.cc

codigo.cc: mlc exemplo.ml
	./mlc < exemplo.ml > codigo.cc
	./gabarito < codigo.cc

lex.yy.c: tipos.l
	lex tipos.l

y.tab.c: tipos.y
	yacc tipos.y

mlc: lex.yy.c y.tab.c
	g++ -o mlc y.tab.c -ll
