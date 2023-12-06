all: scanner

scanner: main.o scan.o
	gcc main.o scan.o -o scanner

scan.o: scan.c
	gcc -c scan.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f scanner *.o
