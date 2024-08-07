#include<stdio.h>
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
	struct test t;
	
	t.a=10;
	t.b=15.5;
	strcpy(t.name,"abcd");
	
	display(&t);
	
}    
	
  void display(struct test *t)
    {
       printf("a= %d\n",t->a);
	   printf("b= %f\n",t->b);
	   printf("name = %s\n",t->name);
    }
	 
/* void display(struct test *t)
    {
       printf("a= %d\n",(*t).a);
	   printf("b= %f\n",(*t).b);
	   printf("name = %s\n",(*t).name);
    }
*/		
