#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------
// Node implementation
//------------------------------------------------
typedef struct _node {
	int _data;
	struct _node* _next;
} Node;

Node* QNode_alloc(int data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	return p;
}

void QNode_free(Node* node) {
	free(node);
}
//------------------------------------------------



//------------------------------------------------
// List implementation
//------------------------------------------------
typedef struct _Queue {
	Node* _head;
	size_t _size;
}Queue;

Queue* Queue_alloc() {
	Queue* p= (Queue*)malloc(sizeof(Queue));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void Queue_free(Queue* q) {
	if (q==NULL) return;
	Node* p1= q->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		QNode_free(p2);
	}
	free(q);
}

size_t Queue_size(const Queue* q) {
	return q->_size;
}

int Queue_firstData(const Queue* q) {
	return q->_head->_data;
}

void Queue_enqueue(Queue* q,
					  int data) {
	q->_head= QNode_alloc(data,q->_head);
	++(q->_size);
}
int Queue_dequeue(Queue* q){
	Node* ptr = q->_head;
	while(ptr->_next->_next){
		ptr = ptr->_next;
	}
	Node* delete_node = ptr->_next;
	ptr->_next=NULL;
	int data = delete_node->_data;
	QNode_free(delete_node);
	--(q->_size);
	return data;
}
void Queue_print(const Queue* q) {
	const Node* p= q->_head;
	while(p) {
		printf("(%d)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",q->_size);
}


//------------------------------------------------
