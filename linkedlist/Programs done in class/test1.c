#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct test
	{
		int *p;
		int a;
	};
	
	struct test t1, *pt;
	t1.a=10;
	int j=10;
	t1.p=&j;
	*(t1.p)=20; // same as the above
	printf("j=%d ",j);
	
	 pt=(struct test*)malloc(sizeof(struct test));
	 
	pt->a=25;
	(*pt).a=45;
	pt->p=&j;
	(*pt).p=&j; // same as the above
	*((*pt).p)=48;
	printf("%d ",j);
}


	
	
	
	
	
	
	
	
	
	