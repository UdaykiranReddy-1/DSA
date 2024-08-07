#include<stdio.h>
#include<stdlib.h>
//program to create 2D array dynamically, store and display the values
//using a function
int main()
{
	void display(int**);
	int row,col;
	row=3,col=3;
	int i,j;
	int **p;
	
	p=(int**)malloc(sizeof(int*)*row);
	
	for(i=0;i<3;i++)
		 p[i]=(int*)malloc(sizeof(int)*col);
	 
	 printf("Enter the values of 2D array..\n");
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		   //scanf("%d",(p[i]+j));
	       scanf("%d",&p[i][j]);
	 }	   
		
     display(p);
}
   
   
   
   
   void display(int **p)
   {
	   int i,j;
      printf("the values of 2D array..\n");
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		  // printf("%d ",*(p[i]+j));
	     printf("%d ",p[i][j]);
	   printf("\n");
	 }	  
   }

		
		 
		 
	 
	 