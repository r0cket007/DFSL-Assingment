#include "bits/stdc++.h"
using namespace std;
const int N = 20;
int printSolution(int dist[],int n)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i=1; i<=n; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
int minDistance(int dist[], bool visited[],int n)
{
    int min=INT_MAX,min_index;
    for (int v=0; v<n; v++)
    {
      if (visited[v]==false && dist[v]<=min)
      {
        min=dist[v], min_index=v;
      }
    }
    return min_index;
}
dijisktra(int v[N][N],int s,int n)
{
  int dist[n];
  bool visited[n]={0};
  dist[s]=0;
  for(int i=1;i<=n;i++)
  {
    if(i!=s) dist[i]=INT_MAX;
  }
  for(int count=1;count<n;count++)
  {
      int u=minDistance(dist,visited,n);
      visited[u] = true;
      for(int i=1; i<=n; i++)
      {
        if (!visited[i] && v[u][i]  && dist[u]!=INT_MAX && dist[u]+v[u][i] < dist[i])
        {
          dist[i]=dist[u] + v[u][i];
        }
      }
  }
    printSolution(dist,n);
}
int main()
{
  cout<<"\nENTER NO OF VERTICES :";
  int n;
  cin>>n;
  int v[N][N];
  int m=1;
  int a,b;
  int cost;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      v[i][j]=0;
    }
  }
  while(m)
  {
    cout<<"\nENTER VERTICES B/W WHICH EDGE IS PRESENT \n";
    cin>>a>>b;
    cout<<"\nENTER THE COST OF THE MATRIX :";
    cin>>cost;
    v[a][b]=cost;
    v[b][a]=cost;
    cout<<"\nWANT TO CONTINUE";
    cin>>m;
  }
  int s;
  cout<<"\nFROM WHERE YOU WANT TO FIND THE MINIMUM DISTANCE :";
  cin>>s;
  dijisktra(v,s,n+1);
	return 0;
}
