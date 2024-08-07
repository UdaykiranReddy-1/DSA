#include<stdio.h>
 //implement heap by using bottom up technique
 //delete the largest number and recreate the heap
 //after deletion
  void bot_heap(int*,int);
  void top_heap(int *, int);
  int max_delete(int*, int*);
  void heapify(int*, int);
  int main()
  {
    int h[100];//heap;
    int i,n,max;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
   bot_heap(h,n-1);//pass index of the last element 
   printf("After creating heap using bottom up approach..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);

   max=max_delete(h,&n);
   printf("\nThe largest element deleted = %d",max);
   printf("\nThe heap after deletion..\n");
   for(i=0;i<n;i++)
      printf("%d ",h[i]);

  }

void bot_heap(int *h, int n)//n is the index of the last element
 {
	 int i,j,k,key;
	 for(k=(n-1)/2; k>=0 ;k--)
	 {
		 j=k;
		 key=h[j];
		 i=2*j+1;//find the left child
		 while(i<=n) //until the left child exits
		 {
			 if((i+1)<=n) //check if the right child exists
			 {
				 if(h[i+1]>h[i]) 
					 i++; // index of the largest child
			 }
			 if(key < h[i])//compare the key with the largest child
			 {
				h[j]=h[i];//move the child up
			   j=i;
              i=2*j+1	;
			 }
			 else
				 break;
		 }			 
		h[j]=key;  //insert key at its proper place	 
	 }		 
 }		 

  int max_delete(int *h, int *n)
  {
	  int key;
	  
	  key=h[0];
	  h[0]=h[*n-1];
	  --*n;
	  heapify(h,*n-1);
	  return key;
  }
  
void heapify(int *h, int n)//n is the index of the last element
 {
	 int i,j,k,key;
	 
		 j=0;
		 key=h[j];
		 i=2*j+1;//find the left child
		 while(i<=n) //until the left child exits
		 {
			 if((i+1)<=n) //check if the right child exists
			 {
				 if(h[i+1]>h[i]) 
					 i++; // index of the largest child
			 }
			 if(key < h[i])//compare the key with the largest child
			 {
				h[j]=h[i];//move the child up
			   j=i;
               i=2*j+1	;
			 }
			 else
				 break;
		 }			 
		h[j]=key;  //insert key at its proper place	  
 }		 

	  























