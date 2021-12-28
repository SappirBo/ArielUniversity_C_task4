#pragma once

#include <stdlib.h>

/********************************************************************************
 *
 * A Graph library.
 *
 * This library implements a Graph data structure containing a list of nodes and edges (E and V) .
 *
 *
 ********************************************************************************/

/*
 * Graph represents a Graph data structure.
 */
struct _graph;
typedef struct _graph Graph;

/*
 * Allocates a new empty Graph.
 * It's the user responsibility to free it with Graph_free.
 */
Graph* Graph_alloc();

/*
 * Frees the memory and resources allocated to g.
 * If list==NULL does nothing (same as free).
 */
void Graph_free(Graph* g);

/*
 * Returns the number of nodes in the Graph.
 */
size_t Graph_size(const Graph* g);

/*
 * Inserts an node in the begining of the node list.
 */
void Graph_insertNode(Graph* g, double data);

/*
* Inserts an edge in the begining of the edge list
*/
void Graph_insertEdge(Graph* g, double weight, int src, int dest);
/*
 * Returns the node list first node.
 */
double V_firstNode(const Graph* g);
/*
 * Returns the edge list first edge.
 */
double E_firstEdge(const Graph* g);
/*
 * Prints the list to the standard output.
 */
void Graph_print(const Graph* g);

/*
 * Checks if two lists have the same elements
 * returns 0 if not and any other number if yes
 */
// int List_equal(const List* list1, const List* list2);

/*
 * Clones the given list. 
 * It's the user responsibility to free it with List_free.
 */
// List* List_clone(const List* list);


