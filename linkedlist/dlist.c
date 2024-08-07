//implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node node_t;

  
struct doubly_linked_list
{
	node_t* head;
	node_t* tail;
	int size;
};

typedef struct doubly_linked_list list_t;
 
  
list_t* create_list();  // return a newly created empty doubly linked list
void insert_front(list_t* list, int data);  // inserts data to the beginning of the linked list
void insert_back(list_t* list, int data); // inserts data to the end of the linked list
void insert_after(list_t* list, int data, int prev); // inserts data after the node with data “prev”
void delete_front(list_t* list); // delete the start node from the linked list.
void delete_back(list_t* list); // delete the end node from the linked list.
void delete_node(list_t* list, int data); // delete the node with “data” from the linked list.
node_t* search(list_t* list, int data); // returns the pointer to the node with “data” field
int is_empty(list_t* list); // return true or 1 if the list is empty; else returns false or 0
int size(list_t* list); // returns the number of nodes in the linked list.  
void delete_list(list_t* list); // free all the contents of the linked list
void display_list(list_t* list); // print the linked list by separating each item by a space and a new line at the end of the linked list.
void reverse(list_t* list);
void shuffle(list_t* list, int k) ;
void k_swap(list_t* list, int k);
void swap(list_t* list,int i,int j);

int main()
{
	int ch,key,pos,value;
	list_t* l =create_list();

    while(1)
	{
		display_list(l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..insert after");
		printf("\n4.delete first node");
		printf("\n5. Delete Last Node..");
		printf("\n6 .Delete a node given value");
		// printf("\n7.Delete at a position");
		// printf("\n8.Insert at a Given Position");
		// printf("\n9. Insert after given value..\n");
		// printf("\n10. Insert before given value..\n");
		printf("\n7. reverse..\n");
		printf("\n8.K-swap");
		// printf("\n12.Exit");
		
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_front(l,key);
						 break;
		    case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_back(l,key);
						 break;			 
		    case 3:	printf("\nEnter the key...");
						scanf("%d",&key);
					printf("\nEnter the nodevalue:..");
						scanf("%d",&value);
						insert_after(l,key,value);
			             break;
		    case 4:delete_front(l);
              			break;		
			case 5:delete_back(l);
              			break;
			case 6: printf("\nEnter the nodevalue:..");
					scanf("%d",&value);
					delete_node(l,value);
						break;
			case 7:reverse(l);
						break;
			case 8: printf("\nEnter the value of K:..");
					scanf("%d",&value);
					swap(l,0,2);			
		 /*  case 6:printf("\nEnter the key...");
			             scanf("%d",&key);
						 delete_node(&l,key);	
                         break;	
		  case 7:printf("\nEnter the position");
			             scanf("%d" ,&pos);
						 delete_pos(&l,pos);
						 break;	
			case 8:printf("\nEnter the key and position");
			             scanf("%d %d" ,&key,&pos);
						 insert_pos(&l,key,pos);
						 break;
			case 9:printf("\nEnter the value and key");
			             scanf("%d %d" ,&value,&key);
						 insert_after(&l,value,key);
						 break;		 
			case 10:printf("\nEnter the value and key");
			             scanf("%d %d" ,&value,&key);
						 insert_before(&l,value,key);
						 break;	*/		 
			case 12:exit(0);
		}
	}
}

list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	//create node
		node_t *temp;
		
		temp=(node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->next=temp->prev=NULL;
		
	  //if first node ?                                                  
	  if(list->head==NULL){
		 list->head=temp;
		 list->tail=temp;
	  }
		 
	  else
	  {
		  temp->next=list->head;
		  list->head->prev=temp;
		  list->head=temp;
	  }
	  list->size++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	//create node
		node_t *temp;
		
		temp=(node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->next=temp->prev=NULL;
		
		// if first node
		 if(list->head==NULL){
			 list->head=temp;
			 list->tail=temp;
		 }
		 
        else
		{
            list->tail->next=temp;
			temp->prev=list->tail;
			list->tail=temp;
		}
		list->size++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* previous=search(list,prev);
	if(previous!=NULL){
		node_t* new=(node_t*)malloc(sizeof(node_t));
		new->data=data;
		new->next=new->prev=NULL;
		if(previous->next!=NULL){
			new->next=previous->next;
			previous->next->prev=new;
			new->prev=previous;
			previous->next=new;
		}
		else{
			previous->next=new;
			new->prev=previous;
			list->tail=new;
		}
		list->size++;
	}
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
			node_t *pres;
			
			pres=list->head;
			
			if(pres->next==NULL) {// only one node 
					list->head=NULL;
					list->tail=NULL;
			}
			   
			else
			{
                  pres->next->prev=NULL;
				  list->head=pres->next;
			}
			free(pres);
			list->size--;
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
			node_t *pres;
			
			pres=list->head;	  
				
            if(pres->next==NULL) {// only one node 
				 list->head=NULL;
				 list->tail=NULL;
			}
			  
			 else
			 {
				 list->tail->prev->next=NULL;
				 list->tail=pres->prev;
			 }
			 free(pres);
			 list->size--;
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t *pres;
	 
	 pres=list->head;
	 
	 //find the node
	while((pres!=NULL) &&(pres->data!=data))
		 pres=pres->next;
	if(pres!=NULL) // node found
	{
		//where ?
		
		if((pres->next== NULL)&&(pres->prev==NULL)){//if only one node
				list->head=NULL;
		}
		    
		else if (pres->prev==NULL) //first node
		{
			pres->next->prev=NULL;
			list->head=pres->next;
		}
		else if(pres->next==NULL){	// last node
			pres->prev->next=NULL;
			list->tail=pres->prev;

		}
		else{	// node at any another position
			pres->prev->next=pres->next;
			pres->next->prev=pres->prev;
		}
	}
	free(pres);
	list->size--;
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
	node_t* temp;
	temp=list->head;
	while((temp!=NULL)&&(temp->data!=data)) temp=temp->next;
	if(temp!=NULL){	// node found
		return temp;
	}
	else return NULL;	// node not found or else temp is empty(empty list)
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

void reverse(list_t* list) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	node_t* curr = list->head;
	node_t* nextnode;
 
    // traverse the list
    while (curr != NULL)
    {
        nextnode=curr->next;
		curr->next=curr->prev;
		curr->prev=nextnode;
		curr=nextnode;
    }
	curr=list->head;
	list->head=list->tail;
	list->tail=curr;
}

	
void swap(list_t* list,int i,int j){
	int flag=0;
	node_t* nodex=list->head;
	node_t* nodey=list->head;
	while(flag<i){
		nodex=nodex->next;
		flag++;
	}
	flag=0;
	while(flag<j){
		nodey=nodey->next;
		flag++;
	}
	if((nodex->prev==NULL)&&(nodey->next==NULL)){
		node_t*headnext=list->head->next;
		node_t*tailprev=list->tail->prev;
		nodey->prev=NULL;
		nodey->next=headnext;
		headnext->prev=nodey;
		list->head=nodey;
		nodex->next=NULL;
		nodex->prev=tailprev;
		tailprev->next=nodex;
		list->tail=nodex;
	}
	else if((nodex->prev==NULL)&&(nodey->next!=NULL)){
		node_t *headnext=list->head->next;
		nodex->next=nodey->next;
		nodex->prev=nodey->prev;
		nodex->prev->next=nodex;
		nodex->next->prev=nodex;
		nodey->prev=NULL;
		nodey->next=headnext;
		headnext->prev=nodey;
		list->head=nodey;
	}
	else if((nodex->prev!=NULL)&&(nodey->next==NULL)){
		node_t*tailprev=list->tail->prev;
		nodey->next=nodex->next;
		nodey->prev=nodex->prev;
		nodey->next->prev=nodey;
		nodey->prev->next=nodey;
		nodex->next=NULL;
		nodex->prev=tailprev;
		tailprev->next=nodex;
		list->tail=nodex;
	}
	else if((nodex->prev!=NULL)&&(nodey->next!=NULL)){
		node_t*secondn=nodey->next;
		node_t*secondp=nodey->prev;
		nodey->next=nodex->next;
		nodey->prev=nodex->prev;
		nodey->next->prev=nodey;
		nodey->prev->next=nodey;
		secondp->next=nodex;
		nodex->prev=secondp;
		nodex->next=secondn;
		secondn->prev=nodex;
	}
}

void k_swap(list_t* list, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	for(int i=0;i+k<=list->size;i++){
		swap(list,i,i+k);
	}
}

void shuffle(list_t* list, int k) // TODO: perform k_swap and reverse
{
	k_swap(list,k);
	reverse(list);
}
		
		
		
		
		





		
			
			
		