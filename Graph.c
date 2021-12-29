#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

#define Max 1000000 

//------------------------------------------------
// Node implementation
//------------------------------------------------
typedef struct _node {
	int _data;
	struct _node* _next;
} Node;

Node* Node_alloc(int data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	if(!p){
		printf("NO SPACE N");
	}
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
	if(!p){
		printf("NO SPACE E");
	}
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

Graph* Graph_alloc() {
	Graph* p= (Graph*)malloc(sizeof(Graph));
	if(!p){
		printf("NO SPACE G");
	}
	p->_headv= NULL;
	p->_heade= NULL;
	p->_size= 0;
	p->_esize=0;
	return p;
}

void Graph_free(Graph* g) {
	if (g==NULL) return;
	Node* p1= g->_headv;
	Node* p2;
	while(p1) {
		p2= p1;
		p1 = p1->_next;
		Node_free(p2);
	}
	g->_size=0;
	Edge* ep1= g->_heade;
	Edge* ep2;
	while(ep1){
		ep2 = ep1;
		ep1 = ep1->_next;
		Edge_free(ep2);
	}
	g->_esize=0;
	free(g);
}

size_t Graph_size(const Graph* g) {
	return g->_size;
}

Node* V_firstNode(const Graph* g) {
	return g->_headv;
}

Edge* E_firstEdge(const Graph* g) {
	return g->_heade;
}

void Graph_insertNode(Graph* g, int data) {
	g->_headv= Node_alloc(data,g->_headv);
	++(g->_size);
}


void Graph_insertEdge(Graph* g, int src, int dest, double weight){
	g->_heade= Edge_alloc(weight,src,dest,g->_heade);
	++(g->_esize);
}

void Graph_print(const Graph* g) {
	const Node* p= g->_headv;
	printf("Nodes:\n");
	while(p) {
		printf("(%d)->",p->_data);
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

Node* getNode(const Graph* g, int id) {
    Node* ptr = g->_headv;
    while(ptr){
		if(ptr->_data==id){
			return ptr;
		}
        ptr = ptr->_next;
    }
    return NULL;
}

Node* getNodeIndex(const Graph* g, int index) {
    Node* ptr = g->_headv;
	int i =0;
	if(index > Graph_size(g)){
		return NULL;
	}
	else if(index == i){return ptr;}
	else{
		while(i<index){
	        ptr = ptr->_next;
			i++;
    	}
    	return ptr;
	}
}

Edge* getEdge(const Graph* g, int src, int dest) {
	if(src == dest){return NULL;}
	else{
		// printf("Got into 'getEdge': src = %d, dest = %d\n",src,dest);
		Edge* ptr = g->_heade;
    	while(ptr){
			// printf("ptr -> dest: %d\n",ptr->_dest);
			if(ptr->_src == src && ptr -> _dest == dest){
				return ptr;
				break;
			}
			ptr = ptr->_next;		 
    	}
		// printf("got out of while\n");
    	return 	NULL;
	}
}



void deleteNode(Graph* g, int id){
	if(!getNode(g,id)){
		return;
	}
	Node* ptr = g->_headv;
	Edge** tmp =NULL;
    while(ptr){
		if(ptr->_data==id)
		{
			Node* deletednode = ptr;
			g->_headv = ptr->_next;
			Node_free(deletednode);
			g->_size--;
			break;
		}
		else if(ptr->_next->_data==id)
		{
			
			Node* deletednode =ptr->_next;
			if(deletednode->_next==NULL)
			{
				ptr->_next=NULL;
				Node_free(deletednode);
				g->_size--;
				break;
			}
			else
			{
				ptr->_next=ptr->_next->_next;
				Node_free(deletednode);
				g->_size--;
				break;
			}
		}
	
	
        	ptr = ptr->_next;		
    }
	Edge* ep = g->_heade;
	while(ep)
	{
		if(ep->_next==NULL){
			//Graph_print(g);
			break;
		}
		if(g->_heade->_dest==id||g->_heade->_src==id){
			tmp = &(g->_heade->_next);
			Edge* deletedEdge =g->_heade;
			g->_heade=g->_heade->_next;
			Edge_free(deletedEdge);
			g->_esize--;
			ep = g->_heade;						
		}else if(ep->_next->_src==id||ep->_next->_dest==id){	
			Edge* deletedEdge = ep->_next;	
			if(deletedEdge->_next==NULL){
				ep->_next=NULL;
				Edge_free(deletedEdge);
				g->_esize--;
				break;
			}else{
				ep->_next=deletedEdge->_next;
				Edge_free(deletedEdge);
				g->_esize--;
				continue;
			}
		}
		if(tmp){
			ep = *tmp;
			//printf("TMP SRC: %d\n",*(tmp)->_src);
			tmp = NULL;
			
		}else{
			ep = ep->_next;
		}
	}
}

double min(double a, double b){
	if(a <0){
		a=Max;
	}
	if(b<0){
		b=Max;
	}
	if(a<b){return a;}
	else{return b;}
}

//------------------------------------------------
// Function implementation
//------------------------------------------------

int shortestPath(const Graph* g, int id1, int id2){
	double d[Graph_size(g)];
	int visit[Graph_size(g)];
	Queue* q = Queue_alloc();
	for(int i=0; i<Graph_size(g); i++){
		d[i] = Max;
		visit[i]=0;
	}
	d[id1] = 0.0;
	Queue_enqueue(q,id1);
	while(Queue_size(q))
	{
		int ptr = Queue_dequeue(q);
		visit[ptr] = 1;
		Edge* e;
		Node* curr;
		int in;
		// if(ptr == id2)
		// {
		// 	break;
		// }
		if(d[ptr]==Max)
		{
			break;
		}
		else{
			for(int i=0; i<Graph_size(g); i++){
				curr = getNode(g,i);
				in = curr->_data;
				if(in == ptr){continue;}
				else{
					e = getEdge(g,ptr,in);
					if(e){
						double c = d[ptr] + e->_weight;
						d[i] = min(d[i],c);
						if(Queue_contains(q,e->_dest) == 0 && visit[e->_dest] == 0){
							Queue_enqueue(q,in);
						}
					}
				}
			}
		}
	}
	Queue_free(q);
	for(int i=0; i<sizeof(d)/sizeof(double);i++){
		printf("d[%d] = %f\n",i,d[i]);
	}
	if(d[id2] == Max){return -1;}
	else{return d[id2];}
}
