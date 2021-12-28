#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


int fromCharToInt(char c){
    return ((int) c-48);
}


int main()
{
    char input = NULL;
    Graph* graph = Graph_alloc();
    while(scanf("%c",&input) != EOF)
    {
        if(input == 'A')
        {
            int size;
            scanf("%d",&size);
            for(int i=0; i<size; i++){
                Graph_insertNode(graph,i)
            }

        }
        while(input == 'n'){
            int id, dest, weight;
            scanf("%d",&id);
            scanf("%c",&input);
            while(input >= 48 && input <= 57){
                dest = fromCharToInt(input);
                scanf("%d",&weight);
                Graph_insertEdge(graph,id,dest, weight);
                scanf("%c",&input);
            }
        }
        if(input == 'B'){
            int id, dest, weight;
            scanf("%d",&id);
            /**
             * Make new Node --> ID.
             */
            scanf("%c",&input);
            while(input >= 48 && input <= 57){
                dest = fromCharToInt(input);
                scanf("%d",&weight);
                /**
                 * Here we will do function that will add edge to node "id". and reapet this
                 */
            }
        }
        if(input == 'D'){
            int id;
            scanf("%d",&id);
            /**
             * Here we will delete node "id" from our graph.
             */
        }
        if(input == 'S'){
            /**
             * Here we will check the shortest path from source to destination.
             */
            int source, destination;
            scanf("%d",&source);
            scanf("%d",&destination);
            /**
             * dijkstra  Function Here int shortestPath(int id1, int id2);
             */
        }
        if(input == 'T'){
            /**
             * TSP algorithm // k <= 6.
             */
            int size;
            scanf("%d",size);
            int nodesTsp[size];
            for(int i=0; i<size; i++){
                scanf("%d", nodesTsp[i]);
            }
            /**
             * Tsp algorithm - int* tsp(int ids[]); (return pointer to an array - all the nodes {dont mind the order}).
             * Maybe an dynamic algorithm will be the best here -- 6! permutations
             */
        }
    }
    Graph_free(graph);
}
