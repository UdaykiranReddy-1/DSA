#include<stdio.h>
#include<stdlib.h>
//program to allocate memory for an integer dynamically
int main()
{
	int *p;
	
	 p= (int*)malloc(sizeof(int));
	 *p=10;
	 printf("The vaue = %d",*p);
}