//binary search tree using array
#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int *root;
};
typedef struct tree tree_t;

void insert(tree_t *, int);
void preorder_t(tree_t*);
void preorder(int *, int);
void postorder_t(tree_t*);
void postorder(int *,int);
void inorder_t(tree_t*);
void inorder(int*,int);
int minimum(tree_t*);
int maximum(tree_t*);
void init(tree_t*);

void main()
{
  tree_t t;
  int ch,num,k,i;
 init(&t);
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2.Preorder");   
      printf("\n3. Postorder");
      printf("\n4.Inorder");
      printf("\n5. Minimum");
      printf("\n6.Maximum");
      scanf("%d",&ch);
       switch(ch)
       {
        
		case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 insert(&t,num);
                 break;
        case 2: preorder_t(&t);
                 break; 
      	case 3: postorder_t(&t);
                 break;
        case 4:inorder_t(&t);
                 break;
      	case 5 : k=minimum(&t);
                printf("The smallest element = %d",k);
                break;
       	case 6 : k=maximum(&t);
                printf("The largest element = %d",k);
                break;  
        case 7:exit(0);

       }
    }
  }    
  
  void init(tree_t *t)
  {
	  int i;
	  t->root=(int*)malloc(sizeof(int)*100);//array of 100 elements
	  for(i=0;i<100;i++)
		  t->root[i]=-1;
  }
  
  void insert(tree_t * t, int key)
  {
	int  i=0;
	int *x=t->root;
	  
	  while(x[i]!=-1)
	  {
		   if(key<x[i])
			   i=2*i+1;//move left
		  else
			  i=2*i+2;//move right  
	  }
	  x[i]=key;
  }
  
    
 void preorder_t(tree_t *t)
 {
	preorder(t->root, 0);	
 }
	 
	void preorder(int *x, int i)
    {
         if(x[i]!=-1)
		 {
			 printf("%d ",x[i]);
			 preorder(x,2*i+1);
			 preorder(x,2*i+2);
		 }
	}

	void inorder_t(tree_t *t)
 {
	inorder(t->root, 0);	
 }
	 
	 	void inorder(int *x, int i)
    {
         if(x[i]!=-1)
		 {
			 inorder(x,2*i+1);
			 printf("%d ",x[i]);
			 inorder(x,2*i+2);
		 }
	}
	 
	  void postorder_t(tree_t *t)
 {
	postorder(t->root, 0);	
 }
	 
	 	void postorder(int *x, int i)
    {
         if(x[i]!=-1)
		 {
			 postorder(x,2*i+2);
			 postorder(x,2*i+1);
			 printf("%d ",x[i]);
		 }
	}
	 
	 
	
		
	 int minimum(tree_t *t)
	 {
		 int *x;
		 x=t->root;
		 int i=0;
		 while(x[2*i+1]!=-1)
			 i=2*i+1; //move left
		 return x[i];
	 }
		
    int maximum(tree_t *t)
	 {
		 int *x;
		 x=t->root;
		 int i=0;
		 while(x[2*i+2]!=-1)
			 i=2*i+2;  //move right
		 return x[i];
	 }
		 		
		 
		 
/*
//Search for the ‘element’ in the BST

temp = 1
while((Tree[temp]!=element) && (Tree[temp] != -1)) // Loop until the element is found
         if(element < Tree[temp])
                 temp = 2 * temp // Move left
         end if
         else
                temp = 2 * temp + 1 //Move right
       end else
end while
 if(Tree[temp] != -1) // If the element is found
Case 1 - Delete leaf node
         if((Tree[2*temp] == -1) and (Tree[2*temp+1] == -1))
                 Tree[temp] = -1
          end if
Case 2 - Delete node with one child
          else if((Tree[2*temp] == -1) or (Tree[2*temp+1] == -1))
                        if(Tree[2*temp] != -1) // Is the child in the left of temp
                             Call Preorder(Tree[1:N], 2*temp) //Update the whole subtree
                         end if
                         else
                              Call Preorder(Tree[1:N], 2*temp+1)
                          end else
          end else if
Case 3 – Delete node with 2 children
         else
              inorder_N = 2*temp+1 // Inorder successor is surely in the right subtree
              Repeat steps 48,49 while Tree[2*inorder_N] ≠ -1
                        inorder_N = 2*inorder_N
               end Repeat
               Tree[temp] = Tree[inorder_N] // Replace with inorder successor
               if(Tree[2*inorder_N + 1] == -1) // Inorder successor has no child
                       Tree[inorder_N] = -1
               end if
               else // Inorder successor has one child
                       Call Preorder(Tree[1:N], 2*inorder_N+1)
               end else
          end else
    end if
    else
         Print “Element not Found”
    end else
  end Delete_Array_BST

Algorithm Preorder(Tree[1:N], root)

Tree is the array holding the tree
root is the subscript of the root node
The empty positions in an array are denoted by -1
Tree[ceil(root/2)-1] = Tree[root]
Tree[root] = -1
if(Tree[2*root] ≠ -1) // A left child exists
     call Preorder(Tree[], 2 * root)
end if
if ( Tree[2*root+1] ≠ -1) // Does a right child exist
     call Preorder(Tree[], 2 * root+1)
end if
end Preorder

*/