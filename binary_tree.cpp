/*  This is a brilliant code written  by Great Great ANAND KUMAR PANDEY . This is a code for forming  Binary Tree with create,display,height,leave node function
                                        and this is a code is for better understanding of Stack Data Structure and Binary Tree */
#include<bits/stdc++.h>
using namespace std;
#define long long ll;
typedef struct node
{
  struct node *left,*right,*next;
  int data;
}node;
class stackk
{
  node *top;
public:
  stackk()
  {
    top=NULL;
  }
  void push_in_stack( node* data )
  {
    if(top==NULL)
    {
      top=data;
    }
    else
    {
      data->next=top;
      top=data;
    }
  }
  node* pop_from_stack()
  {
    if(top==NULL) return NULL;
    else
    {
      node* temp=top;
      top=top->next;
      return temp;
    }
  }
  bool empty()
  {
    if(top==NULL) return true;
    return false;
  }
};

class binary_tree
{
  node *root;
public:
  binary_tree()
  {
    root=NULL;
  }
  node *create(int data)
  {
    if(data==-1) return NULL;
    node*temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->next=NULL;
    return temp;
  }
  void push(node *curr)
  {
    int data;
    cout<<"ENTER -1 FOR NULL NODES--";
    if(curr==NULL)
    {
      cout<<endl;
      cout<<"\nENTER ROOT DATA: ";
      cin>>data;
      //cout<<"ROOT DATA\n"<<endl;
      root=create(data);
      push(root);
    }
    else
    {
      cout<<endl;
      cout<<"\nENTER LEFT NODE OF "<<curr->data<<" : ";
      cin>>data;
      curr->left=create(data);
      cout<<"\nENTER RIGHT NODE OF "<<curr->data<<" : ";
      cin>>data;
      curr->right=create(data);
      if(curr->left!=NULL) push(curr->left);
      if(curr->right!=NULL) push(curr->right);
    }
  }
  node* call_leave_nodes()
  {
    leave_nodes( root );
  }

  void leave_nodes( node *dummy )
  {
    stackk post;
    while(dummy!=NULL)
    {
      post.push_in_stack(dummy);
      dummy=dummy->left;
    }
    while(!post.empty())
    {
      dummy=post.pop_from_stack();
      node* temp=dummy;
      if(dummy->left==NULL && dummy->right==NULL) cout<<temp->data<<" ";
      dummy=dummy->right;
      while(dummy!=NULL)
      {
        post.push_in_stack(dummy);
        temp=dummy;
        dummy=dummy->left;
        //cout<<1;
      }
    }
    cout<<endl;
  }
  void height()
    {
      if(root==NULL) cout<<"NO ELEMENT PRESENT\n";
      else
      {
        stackk post;
        node* dummy=root;
        int l=0;
        int heig=-1;
        while(dummy!=NULL)
        {
          post.push_in_stack(dummy);
          l++;
          dummy=dummy->left;
        }
        while(!post.empty())
        {
          dummy=post.pop_from_stack();
          node* temp=dummy;
          dummy=dummy->right;
          while(dummy!=NULL)
          {
            post.push_in_stack(dummy);
            l++;
            temp=dummy;
            dummy=dummy->left;
            //cout<<l;

          }
          heig=max(heig,l);
          l--;
        }
        cout<<heig<<endl;
      }
    }
    void display_node()
    {
      display(root);
    }
    void display(node *dummy)
    {
      stackk in;
      while(dummy!=NULL)
      {
        in.push_in_stack(dummy);
        dummy=dummy->left;
      }
      while(!in.empty())
      {
        dummy=in.pop_from_stack();
        cout<<dummy->data<<" ";
        dummy=dummy->right;
        while(dummy!=NULL)
        {
          //cout<<dummy->data;
          in.push_in_stack(dummy);
          dummy=dummy->left;
        }
      }
      cout<<endl;
    }

}obj;
int main()
{
  int choice=-1;
  int n=1,m,key;
  while(choice!=6)
  {
    cout<<"\n-------------------------------------------------------------------MENU----------------------------------\n";
    cout<<"ENTER YOUR CHOICE :\n1.CREATE BINARY TREE\n2.HEIGHT OF BINARY TREE\n3.DISPLAY TREE\n4.COPY BINARY TREE\n5.LEAVE NODES REPRPESENTAION\n6.EXIT\n";
    cin>>choice;
    switch(choice)
    {
      case 1: obj.push(NULL);
              break;
      case 2: {
              cout<<"THE HIEGHT OF THE BINARY TREE IS: ";
              obj.height();
              break;
              }
      case 3: {
                cout<<"PREORDER REPRPESENTAION OF TREE IS :";
                obj.display_node();
                break;
              }
      case 4: {
              binary_tree obj1=obj;
              cout<<"BINARY TREE COPIED TO OBJ1 :";
              obj1.display_node();
              break;
            }
      case 5: {
              cout<<"THE LEAVES NODES ARE :";
              obj.call_leave_nodes();
              break;
              }
      case 6: break;
      default : cout<<"ENTER CORRECT CHOICE\n";
                break;
    }
  }
  return 0;
}
