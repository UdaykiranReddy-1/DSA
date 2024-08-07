#include<stdio.h>
int main()
{
	int a[4]={1,2,3,4};
	int (*y)[4];
	printf("        a= %ld\n",a); // ingeter pointer
	printf("         a+1 = %d\n", a+1);
	printf("        &a = %ld\n",&a); // arry pointer
	printf("        &a+1 = %ld\n",&a+1); 
    y=&a;  // copy the array pointer
                
	printf("y= %ld\n",y);
	
} 
	

	 