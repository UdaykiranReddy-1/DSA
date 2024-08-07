#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next;
};
typedef struct node node_t;
struct queue
{
	struct node * front;
	struct node *rear;
};
typedef struct queue queue_t;

void qinsert(int ,queue_t*);
int qdelete(queue_t *);
void qdisplay(queue_t* );


int main()
{
  int k,x,ch;
  
  queue_t q;
  q.front=q.rear=NULL;
  
  while(1)
  {
    qdisplay(&q);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              qinsert(x,&q);
              
               break;
       case 2:k=qdelete(&q);
	   if(k>=0)
   	     printf("The element deleted = %d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }
 
 
 void qdisplay(queue_t *p)
	 {
		 node_t *pres;
		 
		 pres=p->front;
		 if(pres==NULL)
			 printf("Empty queue..\n");
		 else
		 {
		 	 while(pres!=p->rear)
		   {
			   printf("%d ",pres->data);
			   pres=pres->next;
		   }
		  printf("%d ",pres->data);//print the last node
		 }
	 }	 
	 
void qinsert(int x, queue_t *p)
 {
	 node_t *temp;
	 
	 
	 temp=(node_t *)malloc(sizeof(node_t));
	 temp->data=x;
	 temp->next=NULL;
	 
	 //is this the first element
	 
	 if(p->front==NULL)
	 		 p->front=p->rear=temp;
	else
	{
		p->rear->next=temp;
		p->rear=temp;
	}
 }
 
 int qdelete(queue_t *p)
 {
	 int x;
	 node_t *pres;
	 if(p->front==NULL)
	 {
		 printf ("Empty queue..\n");
		 return -1;
	 }
	 pres=p->front;
	 x=pres->data;
	 
	 //if there is only one node
	 if(p->front==p->rear)
	 	 p->front=p->rear=NULL;
	 else
	 	 p->front=pres->next; // make front point to next node
	free(pres);
	return x;
 }
		 
	 
			 
		 
		 
		 
	 
	 
	 
	 
		 
	 
 
 
 
 
 
