a.out: main.o libass2_17CS10005.a
	gcc main.o -L. -lass2_17CS10005
main.o: main.c myl.h
	gcc -Wall -c main.c
libass2_17CS10005.a: ass2_17CS10005.o
	ar -rcs libass2_17CS10005.a ass2_17CS10005.o
ass2_17CS10005.o: ass2_17CS10005.c myl.h
	gcc -Wall -c ass2_17CS10005.c
clean:
	rm a.out main.o libass2_17CS10005.a ass2_17CS10005.o
