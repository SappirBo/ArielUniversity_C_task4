#include "List.h"
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------
// Node implementation
//------------------------------------------------
typedef struct _node {
	double _data;
	struct _node* _next;
} Node;

Node* Node_alloc(double data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	return p;
}

void Node_free(Node* node) {
	free(node);
}


//------------------------------------------------
// Edge Implementation
//------------------------------------------------
typedef struct _edge {
	double _weight;
	int _src;
	int _dest;
	struct _edge* _next;
} Edge;

Edge* Edge_alloc(double weight,
				 int src, int dest, Edge* next) {
	Edge* p= (Edge*)malloc(sizeof(Edge));
	p->_weight= weight;
	p->_src= src;
	p->_dest= dest;
	p->_next= next;
	return p;
}

void Edge_free(Edge* edge) {
	free(edge);
}


//------------------------------------------------
// Graph implementation
//------------------------------------------------
typedef struct _graph {
	Node* _headv;
	Edge* _heade;
	size_t _size;
	size_t _esize;
}Graph;

Graph* _alloc() {
	Graph* p= (Graph*)malloc(sizeof(Graph));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void Graph_free(Graph* g) {
	if (g==NULL) return;
	Node* p1= g->_headv;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		Node_free(p2);
	}
	Edge* ep1= g->_heade;
	Edge* ep2;
	while(p1){
		p2 = p1;
		p1 = p1->_next;
		Edge_free(p2);
	}
	free(g);
}

size_t Graph_size(const Graph* g) {
	return g->_size;
}

double V_firstNode(const Graph* g) {
	return *(g->_headv);
}

double E_firstEdge(const Graph* g) {
	return *(g->_heade);
}

void Graph_insertNode(Graph* g,
					  double data) {
	g->_headv= Node_alloc(data,g->_headv);
	++(g->_size);
}

void Graph_insertEdge(Graph* g, double weight, int src, int dest){
	g->_heade= Edge_alloc(weight,src,dest,g->_heade);
	++(g->_esize);
}

void Graph_print(const List* list) {
	const Node* p= g->_headv;
	printf("Nodes:\n");
	while(p) {
		printf("(%.2f)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",g->_size);
	const Edge* pe = g->_heade;
	printf("Edges:\n");
		while(pe) {
		printf("(src: %d,dest: %d,weight: %.2f)->",pe->_src,pe->_dest,pe->_weight);
		pe= pe->_next;
	}
	printf("|| edge size:%zu\n",g->_esize);
}

// int List_equal(const List* list1, const List* list2) {
// 	const int eq= 0;
// 	const int neq= 1;
	
// 	const Node* p1= list1->_head;
// 	const Node* p2= list2->_head;
// 	while(p1) {
// 		if (p2==NULL||p1->_data!=p2->_data) return neq;
// 		p1= p1->_next;
// 		p2= p2->_next;
// 	}
// 	if (p2!=NULL) return neq;
// 	return eq;
// }

// List* List_clone(const List* list) {
// 	List* ret= List_alloc();
// 	const Node* old= list->_head;
// 	Node** copy= &(ret->_head);
// 	ret->_size= list->_size;
// 	while(old) {
// 		*copy= Node_alloc(old->_data,NULL);
// 		old= old->_next;
// 		copy= &((*copy)->_next);
// 	}
// 	return ret;
// }
//------------------------------------------------
