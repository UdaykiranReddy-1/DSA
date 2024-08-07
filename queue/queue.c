#include "queue.h"

void init(queue_t *ptr_q)
{
	printf("Enter the max size of the queue");
	scanf("%d", &ptr_q->size);
	
	ptr_q->item=(int*)malloc(sizeof(int)*ptr_q->size);
	
	ptr_q->f=ptr_q->r=-1;
}


 int qinsert(queue_t *ptr_q, int data)
 {
	 //check for queue full
	 if(ptr_q->r==ptr_q->size-1)
	 {
		 printf("\nQueue full...cannot insert");
		 return -1;
	 }
	 //increment rear 
	 ptr_q->r++;
	 
	 ptr_q->item[ptr_q->r]=data;
	 if(ptr_q->f==-1) //first element
	    ptr_q->f=0;
     return 1;
 }
	
	int qdelete(queue_t *ptr_q)
	{
		int x;
		//check if queue is empty
		
		if(ptr_q->f==-1)
		{
			printf("Empty queue..cannot delete");
			return -1;
		}
		x=ptr_q->item[ptr_q->f]; //get the first element
		
		//if only one element in queue
		if(ptr_q->f==ptr_q->r)
			ptr_q->f=ptr_q->r=-1;
		else
			ptr_q->f++;
	
	return x;
	}
	void display(queue_t *ptr_q)
    {
		int i;
        if(ptr_q->f==-1)
			printf("\nEmpty queue..");
		else
		{
			for(i=ptr_q->f ;i<=ptr_q->r;i++)
				printf("%d ",ptr_q->item[i]);
		}
	}


		
		
		
		
		
		
		
		
		
		
		
		
	
		
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 