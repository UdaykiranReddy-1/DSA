#include<stdio.h>
#include<stdlib.h>
//program to allocate memory for an array dynamically
int main()
{
	int *p;
	int i,n;
	
	printf("Enter the size of the array..");
	scanf("%d",&n);
	
	 p= (int*)malloc(sizeof(int)*n); // allocate memory for n integers
	 
	 printf("enter the values..");
	 
	 for(i=0;i<n;i++)
		 scanf("%d", (p+i));// or scanf("%d",&p[i]);
	 
	 printf("The values in the array..\n");
	 
	 	 for(i=0;i<n;i++)
		 printf("%d  ", *(p+i));// or printf("%d",p[i]);
	 
}