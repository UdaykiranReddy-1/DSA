//program to implement a threaded binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
  bool lthread;
  bool rthread;
};

typedef struct tnode tnode_t;
struct tree
{
	tnode_t *root;
};

typedef struct tree tree_t;

void insert(tree_t *,int);
void inorder(tnode_t*);
struct tnode_t *inordersuccessor(tnode_t*);
void main()
{
  tree_t t;
  int ch,num,k;
  t.root=NULL;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2..Inorder Traversal.");
      printf("\n3.exit");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 insert(&t,num);
                 break;
         
         case 2:printf("Inorder traversal..\n");
               inorder(t.root);
               break;

         case 3:exit(0);
       }
    }
  }    
    
  void insert(tree_t *t, int key)
  {
	  
	  tnode_t *curr,*temp;
	  
	  temp=(struct tnode*)malloc(sizeof(struct tnode));
	  temp->data=key;
	  temp->left=temp->right=NULL;
	  temp->lthread=temp->rthread=true;
	  
	  curr=t->root;
	  
	if(curr==NULL) //creating root
	    t->root=temp;
	else
	{		
	    while(1)
	    {
		  if(key < curr->data)
		  {
		     if(curr->lthread==false)
			    curr=curr->left;
		    else
			  break;
		  }
		  if(key >curr->data)
		  {
			  if(curr->rthread==false)
				  curr=curr->right;
			  else
				  break;
		  }	    
	  }
	  if(key <curr->data)
	  {
		  temp->left=curr->left;
		  temp->right=curr;
		  curr->left=temp;
		  curr->lthread=false;
	  }
	else
	 {
		temp->left=curr;
		temp->right=curr->right;
		curr->right=temp;
		curr->rthread=false;
     	}	  	   
    }		  
  }
  
  void inorder(tnode_t *t)
  {
	  struct tnode *curr;
	  if(t==NULL)
		  printf("Empty tree");
	  else
	  {
		  curr=t;
		  while(curr->lthread==false)
			  curr=curr->left;
		  while(curr!=NULL)
		  {
			  printf("%d  ", curr->data);
			  curr=inordersuccessor(curr);
		  }
	  }
  }
		  
struct tnode_t * inordersuccessor(tnode_t *t)
   {
	   if(t->rthread==true)
		   return t->right;
	   t=t->right;
	   while(t->lthread==false)
		   t=t->left;
	   return t; 
   }
	   




















	
	
			
			
		
		
	
		
		
	
	
	
	
	
  
 






















