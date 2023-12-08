all: scanner

scanner: main.o scan.o
	gcc main.o scan.o -o scanner

scan.o: scan.c
	gcc -g -c scan.c

main.o: main.c
	gcc -g -c main.c

clean:
	rm -f scanner *.o
