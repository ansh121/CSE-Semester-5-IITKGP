a.out: main.o myl.a
				c++ main.o -L. -lmyl
main.o: main.c++ myl.h
						c++ -Wall -c main.c++
myl.a: myl.o
						ar -rcs myl.a myl.o
myl.o: myl.c++ myl.h
						c++ -Wall -c myl.c++
clean:
		rm a.out main.o myl.a myl.o