/* 
	Cai dat hang doi su dung ds noi don 
*/

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

typedef int eletype;

typedef struct _QueueNode {
    eletype item;
    struct _QueueNode *Next;
} QueueNode;

typedef struct _Queue
{
    QueueNode *front, *back;
} Queue;


Queue *QueueConstruct() {
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
	   return NULL;  // No memory
    }
    q->front = NULL;
    q->back = NULL;
    return q;
}

/*** Kiem tra Stack rong   ***/
int QueueEmpty(const Queue *q) {
    return (q->front == NULL);
}

/*** Thông báo Stack tràn   ***/
int QueueFull() {
   	printf("\n NO MEMORY! STACK IS FULL");  
    getch();
    return 1;
}

int EnQueue(Queue *q, eletype item) {
    QueueNode *node;
    node = (QueueNode *)malloc(sizeof(QueueNode)); //(1)
    if (node == NULL) {
		QueueFull(); return 1;  // Tràn Stack: het bo nho
    }
    
    node->item = item;
    node->Next = NULL;
    
    if((q->front==NULL)&&(q->back==NULL))
    {
        q->front = node;
        q->back = node;
    }
    else
    {
        q->back->Next = node;
        q->back = node;
    }
    
    return 0;
  }

eletype DeQueue(Queue *q) {
    eletype item;
    QueueNode *node;
    
    if (QueueEmpty(q)) {        //(1)
	   // Empty Queue, can't dequeue
	   return 0;
    }
    
    node = q->front;
    item = node->item;         
    
    if((q->front == q->back) && (q->front != NULL))
    {
        q->front = NULL;
        q->back = NULL;
        free(node);
    }            
    else
    {
        q->front=node->Next;
        free(node);
    }   
     
    return item;               
}

int QueueViaList()
{
    Queue *q = QueueConstruct();
    EnQueue(q,2);
    EnQueue(q,3);
    EnQueue(q,4);
    EnQueue(q,3);
    
    while(!QueueEmpty(q))
         printf(" ket qua dequeue la %d\n",DeQueue(q));
	getch();
	return 1;
}

