all:  main
main: main.o Graph.a Graph.h
	gcc -Wall -g -o main main.o Graph.a
Graph:Graph.a
Graph.a: Graph.o 
	ar -rcs Graph.a Graph.o
Graph.o: Graph.c Graph.h
	gcc -Wall -g -c Graph.c 
main.o: main.c Graph.h
	gcc -Wall -g -c main.c 

.PHONY: clean#.PHONY means that clean is not a file.
clean:
	rm -f *.o *.a  main 