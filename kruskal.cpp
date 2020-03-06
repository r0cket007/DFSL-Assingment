#include <bits/stdc++.h>
using namespace std;
#define V 10
typedef long long ll;
ll parent[V];
int find(int i)
{
	while (parent[i] != i)	i=parent[i];
	return i;
}
void add(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}
void kruskalMST(int cost[][V],int n)
{
	int mincost =0;
	for (int i=1; i<n; i++)
		parent[i]=i;
	int count=0;
	while (count<n-1) {
		int min = INT_MAX, a=INT_MIN, b=INT_MIN;
		for (int i=1; i<n; i++) {
			for (int j=1; j<n; j++) {
				if (find(i)!=find(j) && cost[i][j]<min) {
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		add(a,b);
		cout<<a<<" - "<<b<<"\t"<<min<<endl;
		count++;
		mincost += min;
	}
	cout<<"\n Minimum cost= %d \n"<<mincost;
}
int main()
{
	cout<<"\nENTER NO OF VERTICES :";
  int n;
  cin>>n;
  int v[V][V];
  int m=1;
  int a,b;
  int cost;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      v[i][j]=INT_MAX;
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
	kruskalMST(v,n+1);

	return 0;
}
