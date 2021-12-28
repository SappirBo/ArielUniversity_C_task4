#pragma once

#include <stdlib.h>

/********************************************************************************
 *
 * A List library.
 *
 * This library provides a List of doubles data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 *
 ********************************************************************************/

/*
 * List represents a List data structure.
 */
struct _graph;
typedef struct _graph Graph;

/*
 * Allocates a new empty List.
 * It's the user responsibility to free it with List_free.
 */
Graph* Graph_alloc();

/*
 * Frees the memory and resources allocated to list.
 * If list==NULL does nothing (same as free).
 */
void Graph_free(Graph* g);

/*
 * Returns the number of elements in the list.
 */
size_t Graph_size(const Graph* g);

/*
 * Inserts an element in the begining of the node list.
 */
void Graph_insertNode(Graph* g,
					  double data);

/*
* Inserts an element in the begining of the edge list
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
void Graph_print(const List* list);

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


