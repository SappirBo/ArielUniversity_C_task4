all:  main
main: main.o Graph.a Graph.h Queue.a Queue.h
	gcc -Wall -g -o main main.o Graph.a Queue.a
Graph:Graph.a
Queue:Queue.a
Queue.a: Queue.o
	ar -rcs Queue.a Queue.o
Graph.a: Graph.o 
	ar -rcs Graph.a Graph.o
Graph.o: Graph.c Graph.h Queue.h
	gcc -Wall -g -c Graph.c 
Queue.o: Queue.c Queue.h
	gcc -Wall -g -c Queue.c
main.o: main.c Graph.h Queue.h
	gcc -Wall -g -c main.c 

.PHONY: clean#.PHONY means that clean is not a file.
clean:
	rm -f *.o *.a  main 