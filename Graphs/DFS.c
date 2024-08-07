 //program to implement DFS for a digraph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   
   printf("Enter the source vertex..\n");
   scanf("%d",&v);
   
   printf("The vertices reachable from %d using DFS are..\n",v);
   dfs(v);
 
  }

  void creategraph()
  {
    int i,j;
    while(1)
    {
      printf("Enter the source and the destination vertex of the edge\n");
      scanf("%d %d",&i,&j);
      if((i==-9)&&(j==-9))
       break;
      a[i][j]=1;
    }
  }

  void dfs(int v)
  {
	  int i;
	  visit[v]=1;//mark vertex v as visited
	  printf("%d   ",v);
	  //for all the vertices  i adjacent to v, if i is not visited
	  //call dfs(i)
	  for(i=1;i<=n;i++)
	  {
		  if ( (a[v][i]==1)&&(visit[i]==0))
			 dfs(i);
      }
	  
  }	  
		  
	  
 













     



