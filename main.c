#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#define A 65
#define n 110
#define B 66
int fromCharToInt(char c){
    return ((int) c-48);
}


int main()
{
    char input;
    Graph* graph = Graph_alloc();
    while(input != '\n')
    {
        scanf("%c",&input);
        if(input == A) //ascii[A] = 65
        {
            int size;
            scanf("%d",&size);
            for(int i=0; i<size; i++){
                Graph_insertNode(graph,i);
            }
        }
        while(input == n){ // ascii[n] = 110
            int id, dest, weight;
            scanf("%d",&id);
            scanf("%c",&input);
            scanf("%c",&input);
            //char charid = '0'+id;
            while(input >= 48 && input <= 57){
                dest =fromCharToInt(input);
                scanf("%d",&weight);
                Graph_insertEdge(graph,id,dest, weight);
                scanf("%c",&input);
                scanf("%c",&input);
            }
        }

        if(input == B){  //ascii[B] = 66
            int id, dest, weight;
            scanf("%d",&id);
            /**
             * Make new Node --> ID.
             */
            Graph_insertNode(graph,id);
            scanf("%c",&input);
            scanf("%c",&input);
            while(input >= 48 && input <= 57){
                dest = fromCharToInt(input);
                scanf("%d",&weight);
                /**
                 * Here we will do function that will add edge to node "id". and reapet this
                 */
                Graph_insertEdge(graph,id,dest,weight);
                scanf("%c",&input);
                scanf("%c",&input);
            }
        }
        // if(input == 68){  // ascii[D] = 68
        //     int id;
        //     scanf("%d",&id);
            /**
             * Here we will delete node "id" from our graph.
             */
        // }
        // if(input == 83){  // ascii[S] = 83
            /**
             * Here we will check the shortest path from source to destination.
             */
            // int source, destination;
            // scanf("%d",&source);
            // scanf("%d",&destination);
            /**
             * dijkstra  Function Here int shortestPath(int id1, int id2);
             */
        // }
        // if(input == 84){  // ascii[T] = 84
            /**
             * TSP algorithm // k <= 6.
             */
            // int size;
            // scanf("%d",&size);
            // int nodesTsp[size];
            // for(int i=0; i<size; i++){
            //     scanf("%d", nodesTsp[i]);
            // }
            /**
             * Tsp algorithm - int* tsp(int ids[]); (return pointer to an array - all the nodes {dont mind the order}).
             * Maybe an dynamic algorithm will be the best here -- 6! permutations
             */
    //     }
     }
    Graph_print(graph);
    deleteNode(graph,4);
    Graph_print(graph);
    Graph_free(graph);
}