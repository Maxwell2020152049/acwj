all: parser

parser: main.o scan.o tree.o interp.o expr.o
	gcc main.o scan.o tree.o interp.o expr.o -o parser

interp.o: interp.c
	gcc -g -c interp.c

expr.o: expr.c
	gcc -g -c expr.c

tree.o: tree.c
	gcc -g -c tree.c

scan.o: scan.c
	gcc -g -c scan.c

main.o: main.c
	gcc -g -c main.c

clean:
	rm -f parser *.o
