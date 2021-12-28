all:  main
main: ListMain.o Graph.a Graph.h
	gcc -Wall -g -o main ListMain.o Graph.a
Graph:Graph.a
Graph.a: Graph.o 
	ar -rcs Graph.a Graph.o
Graph.o: Graph.c Graph.h
	gcc -Wall -g -c Graph.c 
ListMain.o: ListMain.c Graph.h
	gcc -Wall -g -c ListMain.c 

.PHONY: clean#.PHONY means that clean is not a file.
clean:
	rm -f *.o *.a  main 