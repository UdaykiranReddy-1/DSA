#include<stdio.h>
#include<stdlib.h>
struct stack
{
	char *s;
	int size;
	int top;
};

typedef struct stack stack_t;

void init_stk(stack_t *);
void push(stack_t *, char);
 int   pop(stack_t *);
 void display(stack_t*);
 

