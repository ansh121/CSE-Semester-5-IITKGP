a.out: lex.yy.o y.tab.o asgn4_16CS30012_main.o
	gcc lex.yy.o y.tab.o asgn4_16CS30012_main.o -lfl

asgn4_16CS30012_main.o: asgn4_16CS30012_main.c
	gcc -c asgn4_16CS30012_main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.c: asgn4_16CS30012.l y.tab.h
	flex asgn4_16CS30012.l

y.tab.c: asgn4_16CS30012.y
	yacc -dtv asgn4_16CS30012.y -W

y.tab.h: asgn4_16CS30012.y
	yacc -dtv asgn4_16CS30012.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o asgn4_16CS30012_main.o y.output a.out

test: 
	./a.out < asgn4_16CS30012_test.c