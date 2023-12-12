all: parser

parser: main.o scan.o tree.o interp.o expr.o expr2.o
	gcc main.o scan.o tree.o interp.o expr.o expr2.o -o parser

interp.o: interp.c
	gcc -g -c interp.c

expr.o: expr.c
	gcc -g -c expr.c

expr2.o: expr2.c
	gcc -g -c expr2.c

tree.o: tree.c
	gcc -g -c tree.c

scan.o: scan.c
	gcc -g -c scan.c

main.o: main.c
	gcc -g -c main.c

clean:
	rm -f parser *.o

test: parser
	./parser input01; \
	./parser input02; \
	./parser input03; \
	./parser input04; \
	./parser input05;
