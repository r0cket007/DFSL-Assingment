#include "bits/stdc++.h"
using namespace std;
const int N = 20;
void printSolution(int parent[], int graph[N][N],int n)
{
    cout<<"Edge \tWeight\n";
    int sum=0;
    for (int i=2; i <=n; i++)
      {
				//sum+=dist[i];
			}
      cout<<"MST IS : "<<sum;
}
int minDistance(int dist[], bool visited[],int n)
{
    int min=INT_MAX,min_index;
    for (int v=1; v<=n; v++)
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
	int parent[n];
  bool visited[n]={0};
  dist[s]=0;
  for(int i=1;i<=n;i++)
  {
    if(i!=s) dist[i]=INT_MAX;
  }
	parent[s]=-1;
  cout<<"Edge \tWeight\n";
  int sum=0;
	for(int count=1;count<n-1.
    ;count++)
  {
      int u=minDistance(dist,visited,n);
      visited[u]=true;
      int min=INT_MAX;
      int pos=u;
      for(int i=1; i<n; i++)
      {
        if (!visited[i] && v[u][i]  && dist[u]!=INT_MAX && v[u][i] < dist[i])
        {
          parent[i]=u,dist[i]=v[u][i];
        }
      }
      u=minDistance(dist,visited,n);
      cout<<parent[u]<<" - "<<u<<" \t"<<v[u][parent[u]]<<" \n";
      sum+=v[u][parent[u]];
  }
    cout<<"\nMST IS: "<<sum<<endl;
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
}
