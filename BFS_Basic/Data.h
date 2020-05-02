#ifndef __Data_H__
#define __Data_H__

typedef struct _Graph {
	char ch;
	struct _Graph **link;
}Graph;

typedef struct _Queue {
	Graph* Graph_link;
	struct _Queue* Queue_link;
}Queue;

#endif
#define ACTUAL

#define NUM_OF_LINK 2
#define NUM_OF_NODE 8
#define TRUE 1
#define FALSE 0
#define FAIL -1
