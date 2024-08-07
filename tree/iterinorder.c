//program for iterative inorder traversal
#include<stdio.h>
#include<stdlib.h>

struct tnode
{
   struct tnode *left;
   struct tnode *right;
   int data;
};

typedef struct tnode tnode_t;   

struct tree
{
	 tnode_t *root;
};

typedef struct tree tree_t;
void insert(tree_t *, int);
void inorder(tree_t*);
tnode_t* stk[100];
void push(tnode_t*);
tnode_t* pop();
int isempty();
int top;

int main()
{
 tree_t t;
 t.root=NULL;
 int num,r,m,k;
 top=-1;
  while(1)
 {

   printf("Enter the element");
   scanf("%d",&num);
   if(num==0)
     break;
   insert(&t,num);
   
 }
 printf("Inorder traversal of the tree..\n");
 inorder(&t);
 }

void inorder(tree_t *t)
  {
	  tnode_t *curr;
	  curr=t->root;
	  
	  while(curr!=NULL)
	  {
		  push(curr);
		  curr=curr->left;
	  }
	  while( !isempty())
	  {
		  curr=pop();
		  printf("%d ",curr->data);
		  if(curr->right!=NULL)
		  {
		    curr=curr->right;
		    while(curr!=NULL)
			{
				push(curr);
				curr=curr->left;
			}
		  }
	  } 
  }

void push(tnode_t *x)
    {
       ++top;
        stk[top]=x;
	}

   tnode_t *pop()
   {
	   tnode_t *x;
	   x=stk[top];
	   top--;
	   return x;
   }
	
int isempty()
 {
  if(top==-1)
    return 1;
return 0;
 }

   void insert(tree_t *t, int x)
   {
	   tnode_t *curr, *prev,*temp;
	   curr =t->root;
	   prev=NULL;
	   
	   //create a node
	   temp=(tnode_t*)malloc(sizeof(tnode_t));
	   temp->data=x;
	   temp->left=temp->right=NULL;
	   
	   if(curr==NULL) // first element
	     t->root=temp;
		else
		{
			while(curr!=NULL) // find the leaf node
			{
			 prev=curr;
			 if(x > curr->data)
				curr=curr->right;
			 else
				curr=curr->left;
	     	}
		   if(x>prev->data) // insert to left or right of leaf node
			   prev->right=temp;
		   else
			   prev->left=temp;
		}
   }
