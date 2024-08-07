#include "cqueue.h"

void init(queue_t *ptr_q)
{
	printf("Enter the size of the queue");
	scanf("%d", &ptr_q->size);
	
	ptr_q->cq=(int*)malloc(sizeof(int)*ptr_q->size);
	
	ptr_q->f=ptr_q->r=-1;
}
	
	
	int qinsert(queue_t* ptr_q,int x)
	{
		//check for queue full
		
		if((ptr_q->r +1) %ptr_q->size ==ptr_q->f)
		{
		  printf("Circular queue full. cannot insert");
	      return -1;
		}
		
		//increment rear pointer
		
		ptr_q->r=(ptr_q->r+1)%ptr_q->size ;
		
		ptr_q->cq[ptr_q->r]=x;
		if(ptr_q->f==-1) // for first element
			ptr_q->f=0;
		return 1;
	}
		
	 int qisempty(queue_t* ptr_q)
	 {
		 if(ptr_q->f==-1)
			 return 1;
		 return 0;
	 }
		 
	
	 int qdelete(queue_t* ptr_q)
	 {
		 int x;
		 if(qisempty(ptr_q))
		 {
			 printf("Queue empty..");
			 return -1;
		 }
		
		  x= ptr_q->cq[ptr_q->f];
		  //if only one element
		  if(ptr_q->r==ptr_q->f)
			 ptr_q->r=ptr_q->f=-1; 
		 else
			 ptr_q->f=(ptr_q->f+1) %ptr_q->size;
		 return x;
	 }
			  
void display(queue_t *ptr_q)
{
         int i, f,r,size;
		 
		 f=ptr_q->f;
		 r=ptr_q->r;
		 size=ptr_q->size;

        if(qisempty(ptr_q))
			printf("\nQueue empty...");
		else
		  {
			for(i=f;i!=r;i=(i+1)%size)
				printf("%d    ",ptr_q->cq[i]);
			printf("%d ",ptr_q->cq[i]);
		  }
}	
			
		    

			
		  
		  
		  
		
		 
		 
		 
		 
		 
		 
		 
		
		
		
		
		
			
			
			
			
		
		
		
		
		
		
	
	
	
	
	
	