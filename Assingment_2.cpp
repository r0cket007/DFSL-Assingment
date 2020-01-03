
/* Q- Implement Priority queue as abstract data type using multiple linked list for servicing paitent in a Hospital witth Priority as 1. Serious, 2. Medium and
3. General */
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
  string name;
  int priority;
  struct Node* next;
}node;


class Queue
{
  node* front;

public:

  Queue()
  {
    front=NULL;
  }
  void enqueuee(string data,int pri)
  {
    node *p=new node;
    p->name=data;
    p->next=NULL;
    p->priority=pri;
    if(front==NULL)
    front=p;
    else
    {
      if(pri==3)
      {
        p->next=front;
        front=p;
      }
      else if(pri==2)
      {
        node* dummy=front;
        if(front->priority<pri)
        {
          node *temp=front;
          front=p;
          front->next=temp;
          return;
        }
        while(dummy->next!=NULL && (dummy->next)->priority>2)
        {
          dummy=dummy->next;
        }
        node*temp=dummy->next;
        dummy->next=p;
        p->next=temp;
      }
      else
      {
        node *dummy=front;
        while(dummy->next!=NULL) dummy=dummy->next;
        dummy->next=p;
      }
    }
  }
  void popp()
  {
    if(front==NULL) cout<<"QUEUE IS EMPTY"<<endl;
    else
    {
      node *temp=front;
      front=front->next;
      delete(temp);
    }
  }
  void display_specific(int pri)
  {
    node *dummy=front;
    if(front==NULL)
    {
      cout<<"EMPTY QUEUE\n";
      return;
    }
    while(dummy!=NULL && dummy->priority!=pri) dummy=dummy->next;
    if(dummy==NULL)
    {
      cout<<"NO PATIENT OF SUCH PRIORITY IS PRESENT";
      return;
    }
    while(dummy!=NULL && dummy->priority==pri)
    {
      cout<<dummy->priority<<" "<<dummy->name<<"\n";
      dummy=dummy->next;
    }
    cout<<endl;
  }
  void display()
  {
    node *dummy=front;
    if(front== NULL)
    {
      cout<<"EMPTY QUEUE\n";
      return;
    }
    while(dummy!=NULL)
    {
      cout<<dummy->priority<<" "<<dummy->name<<"\n";
      dummy=dummy->next;
    }
    cout<<endl;
  }

};



int main()
{
  Queue obj;
  int t=1;
  string name;
  int priority;
  while(t!=5)
  {
    cout<<"\nENTER YOUR CHOICE \n1.INSERT\n2.DELETE\n3.DISPLAY SPECIFIC\n4.DISPLAY\n5.EXIT\n";
    cin>>t;
    switch(t)
    {
      case 1:
      {
        int n=1;
        while(n)
        {
          cout<<"ENTER NAME OF PATIENT: ";
          cin>>name;
          cout<<"ENTER PRIORITY: ";
          cin>>priority;
          obj.enqueuee(name,priority);
          cout<<"\nWANT TO CONTINUE ? (0 To exit) ";
          cin>>n;
        }
        break;
      }
      case 2:
      {
        obj.popp();
        break;
      }
      case 3:
      {
        cout<<"ENTER PRIORITY: ";
        cin>>priority;
        obj.display_specific(priority);
        break;
      }
      case 4:
      {
        obj.display();
        break;
      }
      case 5:
      {
        break;
      }
      default : cout<<"ENTER CORRECT CHOICE\n";

    }
  }
  return 0;
}
