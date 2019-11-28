a.out:	lex.yy.c
		cc lex.yy.c -lfl

lex.yy.c:	ass3_17CS10005.l ass3_17CS10005_main.c
		flex ass3_17CS10005.l ass3_17CS10005_main.c

clean:
		rm a.out lex.yy.c

test:
		./a.out <ass3_17CS10005_test.c
