 #include<stdio.h>

//implement heap by using top down / bottom up technique
  void bot_heap(int*,int);
  void top_down(int*,int);
  
  int main()
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
  bot_heap(h,n-1);//pass index of last element
  // top_down(h,n-1);
   printf("After creating heap..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
   
  }

void top_down(int *h, int n)
{
	   
	   int i,c,parent,key;
	   for(i=1;i<=n;i++)
	   {
		   
		   key=h[i];
		   c=i;
		   parent=(c-1)/2;//find the parent
		   
		   while((c>0)&&(key > h[parent]))
		   {
			 h[c]=h[parent];//move parent down;
             c=parent;
             parent=(c-1)/2;
           }
          h[c]=key; // insert the key
	   }
}		   

  void bot_heap(int *h, int n)//n is the index of last element
   {
	   int c,p,k,key;
	   
	   for(k=(n-1)/2;k>=0;k--)	// starts with last non-leaf node.
	   {
		   p=k;
		   key=h[p];
		   c=2*p+1; // get the left child
		   while(c<=n)//until left child exists
		   {
			   if((c+1)<=n) // to check if right child exists
			   {
				   if(h[c+1]>h[c]) // finding the largest child
					   c++;
			   }
			   if(key<h[c])//compare the key with largest child
			   {
				   h[p]=h[c]; // move child up
				   p=c;	// go to affected subtree
				   c=2*p+1;	// start with its left child ... and repeat the same process.
			   }
			   else
				   break;
		   }
		   h[p]=key;
	   }
   }
		 
		 
		 
	 

/*
// Heap Sort in C

#include <stdio.h>

// Function to swap the position of two elements

void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
	// Find largest among root, left child and right child

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int left = 2 * i + 1;

	// right = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest
	// so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// Swap and continue heapifying if root is not largest
	// If largest is not root
	if (largest != i) {

		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
}

*/
	 
	 
	 



































      






















