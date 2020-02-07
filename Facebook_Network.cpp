/* THIS CODE IS WRITTEN SOLELY BY ANAND KUMAR PANDEY THE CODE IS ALL ABOUT GRAPH AND FACEBOOK NETWORK*/
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
  string name;
  string dob;
  int data;
  struct node * next;
  node(string a,string b,int key)
  {
    data=key;
    name=a;
    dob=b;
    next=NULL;
  }
}node;
typedef struct listt
{
  node *head;
}listt;
class GRAPH
{
  int v;
  listt *arr;
public:
  GRAPH()
  {
    v=-1;
  }
  GRAPH(int value)
  {
    v=value;
    arr=new listt[v];
    for(int i=0;i<v;i++)
    {
      (arr+i)->head=NULL;
    }
  }
  void addedge(int s,int d)
  {
    node* p=new node(d);
    p->next=arr[s].head;
    arr[s].head=p;
    node *q=new node(s);
    q->next=arr[d].head;
    arr[d].head=q;
  }
  void dfs_non_recrusive(int x)
  {
    stack <int> s;
    bool visited[v] = {0};
    s.push(x);
    //if(!visited[x]){ cout<<x<<" "; visited[x] = true;}
    while(!s.empty())
    {
      if(!visited[s.top()]) { cout<<s.top()<<" "; visited[s.top()]=true; }
      node *p=arr[s.top()].head;
      s.pop();
      while(p!=NULL)
      {
        if(!visited[p->data])
        {
          s.push(p->data);
          //visited[p->data]=true;
        }
        p=p->next;
      }
    }
    return;
  }
  void bfs_non_recursive(int x)
  {
    std::cout<< '\n';
    queue<int> q;
    q.push(x);
    bool visited[v]={0};
    while (!q.empty())
    {
      if(!visited[q.front()])
      {
        cout<<q.front()<<'\t';
        visited[q.front()]=true;
      }
      int y=q.front();
      q.pop();
      node *p=arr[y].head;
      while(p!=NULL)
      {
        if(!visited[p->data]) q.push(p->data);
        p=p->next;
      }
    }
  }
  void display()
  {
    bool visited[v]={0};
    for(int i=0;i<v;i++)
    {
        node *dummy=arr[i].head;

          while(dummy!=NULL)
          {
              cout<<i<<" ";
              cout<<dummy->data<<" ";
              visited[dummy->data]=true;
              dummy=dummy->next;
              cout<<endl;
          }
  }
}

};
int main()
{
  GRAPH a(4);
  a.addedge(0,1);
  a.addedge(2,3);
  a.addedge(3,0);
  a.dfs_non_recrusive(0);
  a.bfs_non_recursive(0);
  return 0;
}
