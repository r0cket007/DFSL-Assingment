#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;

class graph
{
    int V, E;
    vector<pair<int, ipair>> edge;
public:
    graph(int a)
    {
        V = a;
    }
    void addedge(int u, int v, int w)
    {
        edge.push_back({w, {u, v}});
    }
    int krushkal();
};
class disjoint
{
    int *rank, *parent;
    int n;
public:
    disjoint(int m)
    {
        n = m;
        parent = new int[m+1];
        rank = new int[m+1];
        for(int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if(rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }
};
int graph::krushkal()
{
    int mst = 0;
    sort(edge.begin(), edge.end());
    disjoint ds(V);
    vector<pair<int , ipair>> :: iterator itr;
    for(itr = edge.begin(); itr != edge.end(); itr++)
    {
        int u = itr->second.first;
        int v = itr->second.second;

        int setu = ds.find(u);
        int setv = ds.find(v);
        if(setu != setv)
        {
            cout<<u<<" - "<<v<<"\t"<<itr->first<<endl;
            mst += itr->first;
            ds. merge(setu, setv);
        }
    }
    return mst;
}
int main()
{

  cout<<"\nENTER NO OF VERTICES :";
  int n;
  cin>>n;
  graph gra(n);
  //int v[V][V];
  int m=1;
  int a,b;
  int cost;
  while(m)
  {
    cout<<"\nENTER VERTICES B/W WHICH EDGE IS PRESENT \n";
    cin>>a>>b;
    cout<<"\nENTER THE COST OF THE MATRIX :";
    cin>>cost;

    gra.addedge(a,b,cost);
    cout<<"\nWANT TO CONTINUE";
    cin>>m;
  }
  cout<<"\n EDGE\tWEIGHT\n";
  cout<<"\nCOST OF MST IS :"<<gra.krushkal();
  return 0;
}
