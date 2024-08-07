/*Flavius Josephus was a famous historian of the first century. During the Jewish-Roman war, 
he was among a band of 41 Jewish rebels trapped in a cave by the Romans. 
Preferring suicide to capture, the rebels decided to form a circle and to kill every third remaining person
 until no one was left. But Josephus, along with an unindicted conspirator, 
 wanted none of this suicide nonsense and therefore quickly calculated 
 where he and his friend should stand in the circle so that they can survive. */

//Implementation of Josephus problem
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int *cq;
	int f,r,size;
};

typedef struct queue queue_t;

void init(queue_t*);
void qinsert(queue_t*,int);
int qdelete(queue_t*);
int qisempty(queue_t*);
int josephus(queue_t*);
int main()
{
   int ch,k,n,i,result;
   
   queue_t q;
   init(&q);
   printf("Enter the number of persons..");
   scanf("%d",&n);
   
   for(i=1;i<=n;i++)
       qinsert(&q,i);
  
   result = josephus(&q);
    printf("The  survivor is =%d\n",result);
}

int josephus( queue_t *ptr_q)
{
	int k;
   while(!qisempty(ptr_q))
   {
	   k=qdelete(ptr_q);
	   qinsert(ptr_q,k);
	   k=qdelete(ptr_q); //delete alternate person
   }
   return k;
}
   
int qisempty(queue_t *ptr_q)
 {
	 if(ptr_q->f==-1)
		 return 1;
	 return 0;
 }

void init(queue_t *ptr_q)
{
   printf("Enter the size of queue..\n");
    scanf("%d",&ptr_q->size);
    ptr_q->f=ptr_q->r=-1;
    ptr_q->cq=(int*)malloc(sizeof(int)*(ptr_q->size));
}	
	 
void qinsert (queue_t *ptr_q, int key)
{
	 ptr_q->r=(ptr_q->r+1)%ptr_q->size; //increment rear 
	 ptr_q->cq[ptr_q->r]=key; // insert the element
	 if(ptr_q->f==-1) //if first element
		 ptr_q->f=0;
}
 
int qdelete(queue_t *ptr_q)
{
	 int key;
	 key=ptr_q->cq[ptr_q->f];
	 if(ptr_q->f==ptr_q->r)//only one element
	    ptr_q->f=ptr_q->r=-1;
	 else
		 ptr_q->f=(ptr_q->f+1)%ptr_q->size;
	 return key;
}
  

/* 
int survivor(struct node **head, int k)		// every 'k'th - person to be killed
{
    struct node *p, *q;
    int i;
 
    q = p = *head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed.\n", p->num);
        free(p);
        p = q->next;
    }
    *head = p;
 
    return (p->num);
}

*/
   
   
   
   
 
   