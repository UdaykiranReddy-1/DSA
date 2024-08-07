
#include<stdio.h>
//sum of array using recursion
int main()
{
	int sum(int*, int);//function prototype
	int a[]={4,1,5,3,2};
	
	int result=sum(a,4);
	printf("\nthe sum of array= %d", result);
}

int sum(int *a, int n)
{
	if(n==0)//one element
                        return a[0];
	 return(sum(a,n-1)  +a[n]);
}


