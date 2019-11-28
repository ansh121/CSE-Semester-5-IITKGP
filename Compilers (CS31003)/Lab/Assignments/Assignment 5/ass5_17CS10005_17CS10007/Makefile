a.out: lex.yy.o y.tab.o ass5_17CS10007_17CS10005_translator.o 
	g++ ass5_17CS10007_17CS10005_translator.o lex.yy.o y.tab.o -lfl
	./a.out > ass5_17CS10007_17CS10005_ans1.out < ass5_17CS10007_17CS10005_test1.c 
	./a.out > ass5_17CS10007_17CS10005_ans2.out < ass5_17CS10007_17CS10005_test2.c 
	./a.out > ass5_17CS10007_17CS10005_ans3.out < ass5_17CS10007_17CS10005_test3.c 
	./a.out > ass5_17CS10007_17CS10005_ans4.out < ass5_17CS10007_17CS10005_test4.c 
	./a.out > ass5_17CS10007_17CS10005_ans5.out < ass5_17CS10007_17CS10005_test5.c 
y.tab.o: y.tab.c
	g++ -c y.tab.c
y.tab.c: ass5_17CS10007_17CS10005.y 
	yacc -dtv ass5_17CS10007_17CS10005.y
lex.yy.o: lex.yy.c y.tab.o 
	g++ -c lex.yy.c
lex.yy.c: ass5_17CS10007_17CS10005.l 
	flex ass5_17CS10007_17CS10005.l
ass5_17CS10007_17CS10005_translator.o: ass5_17CS10007_17CS10005_translator.cxx ass5_17CS10007_17CS10005_translator.h
	g++ -c ass5_17CS10007_17CS10005_translator.cxx
clean:
	rm lex.yy.o y.tab.o ass5_17CS10007_17CS10005_translator.o y.tab.c lex.yy.c a.out yy.tab.h y.output ass5_17CS10007_17CS10005_ans*
