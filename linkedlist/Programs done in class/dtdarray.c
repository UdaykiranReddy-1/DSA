#include<stdio.h>
#include<stdlib.h>
//program to create a 2D array dynamically , store and print the values
int main()
{
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
		  // scanf("%d",(p[i]+j));
	       scanf("%d",&p[i][j]);
	 }	   
		
   printf("the values of 2D array..\n");
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		   //printf("%d ",*(p[i]+j));
	    printf("%d ",p[i][j]);
	   printf("\n");
	 }	  
}
		
		 
		 
	 
	 