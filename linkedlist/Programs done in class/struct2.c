#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//pointers and structures
struct test
	{
		int a;
		float b;
		char name[10];
	};
int main()
{
	void display(struct test*);
	  struct test *t;
	  
	 t= (struct test*)malloc(sizeof(struct test));//structure created dynamically
	
    printf("enter the values ");
    printf("a = ");
    scanf("%d", &t->a);
	printf("b = ");
    scanf("%f", &t->b);
	printf("name = ");
    scanf("%s", t->name);
	
	display(t);
	
}    
	
  void display(struct test *t)
    {
       printf("a= %d\n",t->a);
	   printf("b= %f\n",t->b);
	   printf("name = %s\n",t->name);
    }
	
 