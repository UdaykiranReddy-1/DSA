#include<stdio.h>
int main()
{
 int a[3][3]={1,2,3,
                       4,5,6,
                       7,8,9
             };

 printf("a= %u\n",a); //array pointer 
 printf("a+1 =%u\n",a+1);

 printf("\na[0]= %u\n",a[0]); // integer pointer
 printf("a[0]+1 =%u\n",a[0]+1);

 printf("\n&a[0][0] = %u\n",&a[0][0]); // integer pointer
 printf("&a[0][0]+1 = %u\n",&a[0][0]+1);

 printf("\n&a[0] = %u\n",&a[0]);//array pointer
 printf("&a[0]+1 = %u\n",&a[0]+1);

printf("\n&a= %u\n",&a); // pointer to two d array
printf("&a+1 = %u\n",&a+1);

int (*q)[3][3];
 q=&a;
  
}         









    
