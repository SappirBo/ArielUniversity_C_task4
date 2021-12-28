#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"


int fromCharToInt(int c){
    return ((int) c-48);
}


int main()
{
    int input = NULL;
    Graph* graph = Graph_alloc();
    while(input != '~')
    {
        scanf("%d",&input);
        if(input == 65) //ascii[A] = 65
        {
            int size;
            scanf("%d",&size);
            for(int i=0; i<size; i++){
                Graph_insertNode(graph,i);
            }
            printf("size: %d, input: %c\n",size,input);
        }
        while(input == 110){ // ascii[n] = 110
            int id, dest, weight;
            scanf("%d",&id);
            scanf("%d",&input);
            while(input >= 48 && input <= 57){
                dest = fromCharToInt(input);
                scanf("%d",&weight);
                Graph_insertEdge(graph,id,dest, weight);
                scanf("%d",&input);
            }
        }
        if(input == 66){  //ascii[B] = 66
            int id, dest, weight;
            scanf("%d",&id);
            /**
             * Make new Node --> ID.
             */
            scanf("%d",&input);
            while(input >= 48 && input <= 57){
                dest = fromCharToInt(input);
                scanf("%d",&weight);
                /**
                 * Here we will do function that will add edge to node "id". and reapet this
                 */
            }
        }
        if(input == 68){  // ascii[D] = 68
            int id;
            scanf("%d",&id);
            /**
             * Here we will delete node "id" from our graph.
             */
        }
        if(input == 83){  // ascii[S] = 83
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
        if(input == 84){  // ascii[T] = 84
            /**
             * TSP algorithm // k <= 6.
             */
            int size;
            scanf("%d",&size);
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
    //Graph_print(graph);
    Graph_free(graph);
}
