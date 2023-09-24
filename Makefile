fonction.o: fonction.c fonction.h
	clang -Wall -c fonction.c

main: main.c fonction.o
	clang -Wall -o main fonction.o main.c

clean:
	rm -f *.o main

re:
	make clean; make main