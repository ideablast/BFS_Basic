#include"ALL.h"

#ifdef ACTUAL
extern Queue* front;
extern Queue* rear;

Queue* Add_new_node()
{
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->Graph_link = NULL;
	temp->Queue_link = NULL;

	return temp;
}

void enQueue(Graph* node)
{
	Queue* temp = Add_new_node();
	temp->Graph_link = node;

	if (rear->Queue_link == NULL)
	{
		front->Queue_link = temp;
		rear->Queue_link = temp;
	}
	else
	{
		rear->Queue_link->Queue_link = temp;
		rear->Queue_link = temp;
	}
}

void L_enQueue(Graph* node)
{
	Queue* temp = Add_new_node();
	temp->Graph_link = node;

	if (rear->Queue_link == NULL)
	{
		front->Queue_link = temp;
		rear->Queue_link = temp;
	}
	else
	{
		temp->Queue_link = front->Queue_link;
		front->Queue_link = temp;
	}
}

Graph* deQueue()
{
	Queue* Q_temp;
	Graph* result;

	if (front->Queue_link == NULL)//없을떄
		result = NULL;
	else
	{
		result = front->Queue_link->Graph_link;
		Q_temp = front->Queue_link;
		
		if (front->Queue_link != rear->Queue_link)//여러개 있을때
		{
			front->Queue_link = Q_temp->Queue_link;
			free(Q_temp);
		}
		else//1개만 있을때
		{
			front->Queue_link = Q_temp->Queue_link;
			rear->Queue_link = Q_temp->Queue_link;
			free(Q_temp);
		}

	}

	return result;
}

int Is_Empty()
{
	return front->Queue_link == NULL;
}

Graph** Make_Node(int size)
{
	int i, j;
	Graph** node;

	node = (Graph**)malloc(size * sizeof(Graph*));
	for (i = 0; i < size; i++)
	{
		node[i] = (Graph*)malloc(sizeof(Graph));
		node[i]->ch = 'A' + i;
		node[i]->link = (Graph**)malloc(NUM_OF_LINK * sizeof(Graph*));//0:왼쪽, 1:오른쪽
		for (j = 0; j < NUM_OF_LINK; j++)
			node[i]->link[j] = NULL;
	}

	return node;
}


void BFS_function(Graph* node, int* check_table)
{
	Graph* search = node;
	Graph* enQ_temp = NULL;
	Graph* deQ_temp = NULL;

	int i, cnt = 0;

	while (1)
	{
		for (i = 0; i < NUM_OF_NODE; i++)
		{
			if (check_table[i] == 1)
				cnt++;
		}

		if (cnt == NUM_OF_NODE)
			break;
		else
			cnt = 0;

		if (search)
		{
			check_table[search->ch - 'A'] = 1;
			printf("%c", search->ch);
			for (i = 0; i < NUM_OF_LINK; i++)
			{
				if (search->link[i] && check_table[search->link[i]->ch - 'A'] != 1)
					cnt++;
			}
			if (cnt != 0)
			{
				enQ_temp = search;
				cnt = 0;
			}
			if (Is_Empty() == TRUE)
			{
				if (enQ_temp)
					enQueue(enQ_temp);
				enQ_temp = NULL;
				for (i = 0; i < NUM_OF_LINK; i++)
				{
					if (search->link[i] && check_table[search->link[i]->ch - 'A'] != 1)
					{
						search = search->link[i];
						break;
					}
				}
			}
			else
			{
				if (enQ_temp)
					enQueue(enQ_temp);
				enQ_temp = NULL;
				deQ_temp = deQueue();
				for (i = 0; i < NUM_OF_LINK; i++)
				{
					if (deQ_temp->link[i] && check_table[deQ_temp->link[i]->ch - 'A'] != 1)
						cnt++;
				}
				for (i = 0; i < NUM_OF_LINK; i++)
				{
					if (deQ_temp->link[i] && check_table[deQ_temp->link[i]->ch - 'A'] != 1)
					{
						search = deQ_temp->link[i];
						break;
					}
				}
				if (cnt > 1)
				{
					if (deQ_temp)
						Queue_Rotation(deQ_temp);
					//L_enQueue(deQ_temp);
					deQ_temp = NULL;
					cnt = 0;
				}
				else
				{
					deQ_temp = NULL;
					cnt = 0;
				}
					
			}
		}
	}
}

int Link_Count(Graph* node)
{
	int cnt = 0;
	int i;
	for (i = 0; i < NUM_OF_LINK; i++)
	{
		if (node->link[i])
			cnt++;
	}
	return cnt;
}

int Count_Queue()
{
	int result;
	int cnt = 0;
	Queue* Count = front->Queue_link;

	if (Count == NULL)
		result = cnt;
	else
	{
		while (Count->Queue_link != NULL)
		{
			cnt++;
			Count = Count->Queue_link;
		}
		cnt++;
		result = cnt;
	}

	return result;
}
void Queue_Rotation(Graph* node)
{
	int cnt_Queue = Count_Queue();
	Graph* temp;
	int i;
	enQueue(node);

	for (i = 0; i < cnt_Queue; i++)
	{
		temp = deQueue();
		enQueue(temp);
	}
}

#endif
