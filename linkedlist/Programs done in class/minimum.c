//program to find the smallest in the array using recursion
#include<stdio.h>
int main()
{
	int min(int*, int);//function prototype
	int a[]={4,1,5,3,2};
	int result=min(a,4);
	printf("\nthe smallest = %d", result);
}

int min(int *a, int n)
{
	int k;
	if(n==0)
		return a[n];
	k=min(a,n-1); // find the smallest of n-1 numbers
	if(k<a[n]) //compare with the nth number
		return k;
	else
		return a[n];
}