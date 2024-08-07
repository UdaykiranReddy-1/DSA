#include<stdio.h>
//program to return the fibonacci number at a given position
int main()
{
   int n;
   int fib(int);
   printf("Enter the number ");
   scanf("%d", &n);
   printf("the fibonacci number at the %d th term =%d",n,fib(n));
   
}

 int fib(int n)
 {
	 int result;
	 if(n==1)
		 return 0;
	 if(n==2)
		 return 1;
	 result=fib(n-1)+fib(n-2);
	 return(result);
 }
 
 
 