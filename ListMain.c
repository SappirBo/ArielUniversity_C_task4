#include "Graph.h"

int main(int argc, char* argv[]) {

	double array[]={2.15,4,6,12,77,99};
	int i;
	int j;
	Graph* gPtr1= Graph_alloc();
	for(i=0; i<(sizeof(array)/sizeof(array[0])); ++i) {
		Graph_insertNode(gPtr1,array[i]);
	}

	for(j=0;j<(sizeof(array)/sizeof(array[0]))-1; ++j){
		Graph_insertEdge(gPtr1,array[j],array[j+1],1);
	}
	Graph_print(gPtr1);
				  
	  
	Graph_free(gPtr1);
	  
	return 0;
}
