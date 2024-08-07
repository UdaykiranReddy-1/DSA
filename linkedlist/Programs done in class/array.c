#include<stdio.h>
//program to display addresses of locations of an array
int main()
{
 
  int a[4]={1,2,3,4};
  int i;

  for(i=0;i<4;i++)
  {
    printf("The adress of %d position = %p,",i,(a+i)) ;
    printf("  The value at %d positions = %d", i, *(a+i));
    printf("\n");
  }

}

  
