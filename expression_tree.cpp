/*  This is a brilliant code written by Great Great ANAND KUMAR PANDEY . This is a code for forming Expression Binary Tree using prefix and Postfix
                              expression and this is a code is for better understanding of Stack Data Structure and Binary Tree */
#include<bits/stdc++.h>
using namespace std;
                                                                        /*NODE STRUCTURE*/
typedef struct node
{

  char data;
  struct node* left;
  struct node* right;
  struct node* next;
}node;
                                                                          /*STACK CLASS*/
class stackk
{
  node *top;
public:
  stackk()
  {
    top=NULL;
  }
  void push_in_stack( node* data )            //push function of Stack ADT
  {
    if(top==NULL)
    {
      top=data;
      top->next=NULL;
    }
    else
    {
      data->next=top;
      top=data;
    }
  }
  node* pop_from_stack()                      //pop function of Stack ADT
  {
    if(top==NULL) return NULL;
    else
    {
      node* temp=top;
      top=top->next;
      return temp;
    }
  }
  bool empty()                                  //to check is stack is empty
  {
    if(top==NULL) return true;
    return false;
  }
};
                                                          /*BINARY TREE CLASS*/
class binary_tree
{
  node *root;
  stackk st;
public:
  binary_tree()
  {
    root=NULL;
  }
  node *create( char data )                     //create Node Function
  {
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->next=NULL;
    return temp;
  }
  void expression_tree_postfix( string s)         //Function for Expression Tree using Postfix
  {
    for(int i=0;i<s.length();++i)
    {
      if( isalpha(s[i]) )
      {
          st.push_in_stack( create(s[i]) );
      }
      else
      {
        node* t2=st.pop_from_stack();
        node* t1=st.pop_from_stack();
        root=create(s[i]);
        root->left=t1;
        root->right=t2;
        st.push_in_stack(root);
      }
    }
    root=st.pop_from_stack();
  }
  void expression_tree_prefix(string s)               //Function for Expression Tree using Prefix
  {
    for(int i=s.length()-1;i>=0;--i)
    {
      if( isalpha(s[i]) )
      {
          st.push_in_stack( create(s[i]) );
      }
      else
      {
        node* t1=st.pop_from_stack();
        node* t2=st.pop_from_stack();
        root=create(s[i]);
        root->left=t1;
        root->right=t2;
        st.push_in_stack(root);
      }
    }
  }
  void display() {                                      //display function
    cout<<endl;
   cout<<"INORDER DISPLAY: ";
   cout<<endl;
   inorder_display(root);
   cout<<endl;
   cout<<"PREORDER DISPLAY: ";
   cout<<endl;
   preorder_display(root);
   cout<<endl;
   cout<<"POSTORDER DISPLAY: ";
   cout<<endl;
   postorder_display(root);
  }
  void postorder_display( node *dummy )                 //non recursive postorder Display
  {
    stackk post1,post2;
    post1.push_in_stack(dummy);
    while(post1.empty()==false)
    {
      node*temp=post1.pop_from_stack();
      post2.push_in_stack(temp);
      if(temp->left!=NULL) post1.push_in_stack(temp->left);
      if(temp->right!=NULL) post1.push_in_stack(temp->right);
      //cout<<1;
    }
    while(post2.empty()==false)
    {
      dummy=post2.pop_from_stack();
      cout<<dummy->data;
    }
    cout<<endl;
  }
  void preorder_display( node *dummy )                    //non recursive Preorder Display
  {
    stackk pre;
    while(dummy!=NULL)
    {
      cout<<dummy->data;
      pre.push_in_stack(dummy);
      dummy=dummy->left;
    }
    while(!pre.empty())
    {
      dummy=pre.pop_from_stack();
      //if(dummy->right==NULL) cout<<dummy->data;
      dummy=dummy->right;
      while(dummy!=NULL)
      {
        cout<<dummy->data;
        pre.push_in_stack(dummy);
        dummy=dummy->left;
      }
    }
    cout<<endl;
  }
  void inorder_display( node *dummy )                         //non recursive Inorder Display
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
      cout<<dummy->data;
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
};
                                                                         /*MENU PROGRAME*/
int main()
{
  binary_tree obj;
  int choice=1;
  int n,m,flag,found;
  while(choice!=3)
  {
    cout<<"\n-------------------------------------------------------------------MENU------------------------------\n";
    cout<<"\nWHAT IS THE FORMAT OF YOUR EXPRESSION :\n1.POSTFIX\n2.PREFIX\n3.EXIT\n";
    cin>>choice;
    cout<<"\nENTER THE EXPRESSION :";
    string s;
    cin>>s;
    if(choice==1) obj.expression_tree_postfix(s);
    else if(choice==2) obj.expression_tree_prefix(s);
    else break;
    obj.display();
  }
  cout<<endl;
  return 0;
}
