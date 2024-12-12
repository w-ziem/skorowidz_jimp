a.out: main.o utils.o skorowidz.o word.o
	gcc -Wall -pedantic main.o skorowidz.o utils.o word.o

main.o: main.c utils.o skorowidz.o word.o
	gcc -c -Wall -pedantic main.c

utils.o: utils.c utils.h
	gcc -c -Wall -pedantic utils.c

skorowidz.o: skorowidz.c skorowidz.h
	gcc -c -Wall -pedantic skorowidz.c

wrod.o: word.c word.h
	gcc -c -Wall -pedantic word.c
