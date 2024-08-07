#include<stdio.h>
//program to fin minimum in an array using recursion
int main()
{
	int a[]={4,2,1,8,9,6,7,5};
	int min(int *, int,int);
	int result=min(a, 0,7);
	printf("The smallest = %d",result);
}

int min(int *a, int low, int high)
{
	if(low==high)//one element
		return a[low];
	int mid=(low+high)/2;
	int left=min(a,low,mid);
	int right=min(a, mid+1, high);
	if(left<right)
		return left;
	return right;
}

