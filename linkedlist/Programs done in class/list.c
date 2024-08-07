#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct list
{
	node_t *head;
};
typedef struct list list_t;
void init_list(list_t*);
void insert_head(list_t *, int);
void display(list_t *);

int main()
{
   list_t l;
   init_list(&l);
    int n,ch;
   while(1)
   {
	   display(&l);
	   printf("\n1..Insert at head\n");
	   printf("2..Insert at end\n");
	   printf("3..display\n");
	   printf("4..exit\n");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		   case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						 insert_head(&l,n);
						 break;
			case 3: display(&l);
			              break;
			case 4:exit(0);
	   }
   }
}

     void display(list_t *ptr_list)
	 {
		 node_t *pres;
        //is list empty ?
		if(ptr_list->head==NULL)
		   printf("Empty list.\n");
	   else
	   {
		   //copy the address of the first node
		   pres=ptr_list->head;
		   while(pres!=NULL)
		   {
			   printf("%d-->",pres->key);
			   pres=pres->link;
		   }
	   }
	 }
			   
		   
		   
		   
		
		 

			
	void insert_head(list_t *ptr_list, int data)
	{	
	    node_t *temp;
		temp=(node_t*)malloc(sizeof(node_t));	
        temp->key=data;
		temp->link=NULL;
		
		//is list empty ?
		if(ptr_list->head==NULL)
			ptr_list->head=temp;
		else
		{
			temp->link=ptr_list->head;
			ptr_list->head=temp;
		}
	}
			
			
		
		
	
		


		
						 
		   
		   




void init_list(list_t *ptr_list)
{
    ptr_list->head=NULL;
}
	
	



