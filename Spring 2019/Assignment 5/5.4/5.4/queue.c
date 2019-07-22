/*
    JTSK-320112
    a5-p4c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void copy_to_node(Item item, Node *pn);
void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    if(queue_is_full(pq))
        return -1;
    //check whether the queue is full
    Node *nn=(Node*)malloc(sizeof(Node));
    //new node
    if(nn==NULL)
    {
        printf("Bad Allocation\n");
        return -1;
    }
    //copy items to nodes
    copy_to_node(item,nn);
    nn->next = NULL;
    //if queue is empty
    if(queue_is_empty(pq))
    {
        pq->front = nn;
        pq->rear = pq->front;
    }
    else
    {
        pq->rear->next = nn;
        pq->rear = pq->rear->next;
    }
    pq->items++;
    return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	// add missing stuff
        return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq))
    {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}
