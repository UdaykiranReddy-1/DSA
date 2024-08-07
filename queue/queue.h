#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int *item;
	int f,r,size;
};

typedef struct queue  queue_t;

int qinsert(queue_t *,int);
int qdelete(queue_t*);
void display(queue_t*);
void init(queue_t*);
