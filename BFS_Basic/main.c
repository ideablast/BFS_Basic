#include "ALL.h"

Queue* front;
Queue* rear;

int main()
{
	int* check_table = (int*)calloc(NUM_OF_NODE, sizeof(int));
	Graph** node = Make_Node(NUM_OF_NODE);

	front = Add_new_node();
	rear = Add_new_node();
	

	node[0]->link[0] = node[1];
	node[0]->link[1] = node[4];
	node[1]->link[1] = node[2];
	node[2]->link[0] = node[3];
	node[2]->link[1] = node[4];
	node[4]->link[0] = node[5];
	node[4]->link[1] = node[6];
	node[3]->link[0] = node[7];
	
	BFS_function(node[0], check_table);
}