//program to check if two trees are identical
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
typedef struct tnode tnode_t;

struct tree
{
	tnode_t *root;
};
typedef struct tree tree_t;

void preorder(tnode_t*);
void create(tree_t*);
void insert(tree_t*, int);
int identical(tnode_t*, tnode_t*);
int  main()
{
  tree_t t1,t2;
  t1.root=t2.root=NULL;
  
  int ch,num,k,n,result;
 
  printf("\nCreating first tree..\n");
  create(&t1);
  printf("\nTraversal in preorder of first tree");
  preorder(t1.root);

  printf("\nCreating second  tree..\n");
  create(&t2);
  printf("\nTraversal in preorder of second tree");
  preorder(t2.root);
    
  result=identical(t1.root,t2.root);
  if(result)
   printf("\nTrees identical..\n");
 else
  printf("\nNot Identical\n");
}
  
  void create(tree_t *t)
  {
	  int num;
    while(1)
    {

     printf("Enter the element");
     scanf("%d",&num);
     if(num==0)
        break;
     insert(t,num);
	}
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
 
 
  int identical(tnode_t *r1, tnode_t*r2)
  {
	  if((r1==NULL)&&(r2==NULL))
		  return 1;
	  if((r1!=NULL)&&(r2!=NULL))
	  {
		 if(r1->data==r2->data)
         {
              int l=identical(r1->left,r2->left);
               if(l==0)
                   return 0;
               int r=identical(r1->right,r2->right);
                return(l&&r);
		 }
		 else return 0;
	  }
	  else return 0;
  }
	  
	void preorder(tnode_t *t)
    {
        if(t!=NULL)
        {
           printf("%d  ",t->data);
           preorder(t->left);
           preorder(t->right);
        }
    }
	
		  
		  
		  
		  
		  
  
	 
	 
	 

  

 
