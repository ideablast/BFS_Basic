#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

/*DFS*/
Graph** Make_Node(int size);
void BFS_function(Graph* node, int* check_table);
int Link_Count(Graph* node);

/*Queue*/
Queue* Add_new_node();
void enQueue(Graph* node);
Graph* deQueue();
void L_enQueue(Graph* node);
void Queue_Rotation(Graph* node);
int Is_Empty();

#endif
//enQUeue, deQueue, IsEmpty, Create