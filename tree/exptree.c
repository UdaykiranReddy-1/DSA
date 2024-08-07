#include<stdio.h>
#include<stdlib.h>
//program to create an expression tree
struct tnode
{
   struct tnode *left;
   struct tnode *right;
   char data;
};

typedef struct tnode tnode_t;   

struct tree
{
	 tnode_t *root;
};

typedef struct tree tree_t;


tnode_t* create_exptree(char*);
int isoper(char);
void push(tnode_t**,int*,tnode_t*);
tnode_t* pop(tnode_t**,int*);
void preorder(tnode_t*);
int evaluate(tnode_t*);
void main()
{
  struct tnode *root;
  int ch,num,k,result;
  char exp[100];
  tree_t t;
  t.root=NULL;  
  printf("Enter the postfix form of the expression...");
  scanf("%s",exp);
  t.root=create_exptree(exp);
  
  /*printf("The infix expression = \n");
  inorder(t.root);*/
  printf("\nThe prefix expression = \n");
  preorder(t.root);
  /*printf("\nThe postfix expression = \n");
  postorder(&t);*/
 printf("\nEvaluating the expression\n");
 result = evaluate(t.root);
 printf("\nThe evaluation of the expression = %d\n",result);
  
}
	 
  int evaluate(tnode_t * t)
  {
	  int a;
	 switch(t->data)
	 {
          case'+': return(evaluate(t->left) + evaluate(t->right)); 
		  case'-':return(evaluate(t->left) - evaluate(t->right)); 
		  case'*':return(evaluate(t->left) * evaluate(t->right)); 
		  case'/':return(evaluate(t->left) / evaluate(t->right)); 
		  default: printf("%c= ",t->data);
		                 scanf("%d",&a);
						 return a;
	 }
  }
		              
					  
   void preorder(tnode_t* t)
   {
	   if(t!=NULL)
	   {
		   printf("%c",t->data);
		   preorder(t->left);
		   preorder(t->right);
	   }
   }
		   
tnode_t* create_exptree(char *exp)
 {
	int i=0;
	 tnode_t *stk[10];
	 tnode_t *temp;
	 int top=-1;
	 char ch;
	 while(exp[i]!='\0')
	 {
		 ch=exp[i];
		 //create node for ch
		 temp=(tnode_t*)malloc(sizeof(tnode_t));
		 temp->data=ch;
		 temp->left=temp->right=NULL;
		 
		 if(isoper(ch))
		 {
	        temp->right=pop(stk,&top);
		    temp->left=pop(stk,&top);
		    push(stk,&top,temp);
	     }
		 else
			 push(stk,&top,temp);
          i++;
	 }
	 return(pop(stk,&top));
 }
	 
void  push(tnode_t **stk, int *t, tnode_t *temp)
	 {
		 ++*t;
		 stk[*t]=temp;
	 }
	 
tnode_t *pop(tnode_t**stk, int *t)
	  {
		  tnode_t *x;
		  x=stk[*t];
		  --*t;
		  return x;
	  }
		  
		 	 
int isoper(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':
      case '*':
      case '/':return 1;
      default: return 0;
    }
  }

 






  























