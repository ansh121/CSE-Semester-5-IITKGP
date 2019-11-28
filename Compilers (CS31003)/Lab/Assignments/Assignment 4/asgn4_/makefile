a.out: lex.yy.o y.tab.o asgn4_17CS10005_main.o
	gcc lex.yy.o y.tab.o asgn4_17CS10005_main.o -lfl

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

asgn4_17CS10005_main.o: asgn4_17CS10005_main.c
	gcc -c asgn4_17CS10005_main.c

lex.yy.c: asgn4_17CS10005.l y.tab.h
	flex asgn4_17CS10005.l

y.tab.c: asgn4_17CS10005.y
	yacc -dtv asgn4_17CS10005.y -W

y.tab.h: asgn4_17CS10005.y
	yacc -dtv asgn4_17CS10005.y -W

test: a.out
	./a.out < asgn4_17CS10005_test.c

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o asgn4_17CS10005_main.o y.output a.out
