a.out: lex.yy.c y.tab.c y.tab.h ass6_17CS10005_17CS10007_translator.h ass6_17CS10005_17CS10007_translator.cxx ass6_17CS10005_17CS10007_target_translator.cxx libmyl.a
	g++ -std=c++11 lex.yy.c y.tab.c ass6_17CS10005_17CS10007_translator.cxx ass6_17CS10005_17CS10007_target_translator.cxx -lfl -o a.out
	

libmyl.a: mylib.o
	ar -rcs libmyl.a mylib.o

mylib.o: mylib.c mylib.h
	gcc -Wall -c mylib.c

y.tab.h: ass6_17CS10005_17CS10007.y
	yacc -dtv ass6_17CS10005_17CS10007.y 	
y.tab.c: ass6_17CS10005_17CS10007.y
	yacc -dtv ass6_17CS10005_17CS10007.y 
lex.yy.c: ass6_17CS10005_17CS10007.l y.tab.h
	flex ass6_17CS10005_17CS10007.l

clean: 
	rm *.out y.tab.h y.tab.c lex.yy.c y.output *.s *.o *.a

test1: a.out ass6_17CS10005_17CS10007_test1.c
	./a.out < ass6_17CS10005_17CS10007_test1.c  1
	gcc -c ass6_17CS10005_17CS10007_1.s
	gcc  ass6_17CS10005_17CS10007_1.o -L. -g -lmyl -o test1.out
	./test1.out

test2: a.out ass6_17CS10005_17CS10007_test2.c
	./a.out < ass6_17CS10005_17CS10007_test2.c 2
	gcc -c ass6_17CS10005_17CS10007_2.s
	gcc  ass6_17CS10005_17CS10007_2.o -L. -g -lmyl -o test2.out
	./test2.out

test3: a.out ass6_17CS10005_17CS10007_test3.c
	./a.out < ass6_17CS10005_17CS10007_test3.c 3
	gcc -c ass6_17CS10005_17CS10007_3.s
	gcc  ass6_17CS10005_17CS10007_3.o -L. -g -lmyl -o test3.out
	./test3.out

test4: a.out ass6_17CS10005_17CS10007_test4.c
	./a.out < ass6_17CS10005_17CS10007_test4.c 4
	gcc -c ass6_17CS10005_17CS10007_4.s
	gcc  ass6_17CS10005_17CS10007_4.o -L. -g -lmyl -o test4.out
	./test4.out


test5: a.out ass6_17CS10005_17CS10007_test5.c
	./a.out < ass6_17CS10005_17CS10007_test5.c 5
	gcc -c ass6_17CS10005_17CS10007_5.s
	gcc  ass6_17CS10005_17CS10007_5.o -L. -g -lmyl -o test5.out
	./test5.out

