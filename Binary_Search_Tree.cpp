#include<bits/stdc++.h>
using namespace std;


typedef struct node         // Structure for Node of Binary tree
{
  int key;
  node *left,*right,*next;
  node(int x)
  {
    key=x;
    left=NULL;
    right=NULL;
    next=NULL;
  }
}node;
//------------------------------CLASS BST----------------------

class BST                   //class Binary Search tree
{
  node* root;
public:
  BST()
  {
    root=NULL;
  }
  void insert_main(int data)
  {
    insert(root,data);
  }
  void insert(node* dummy,int data)
  {
    if(dummy==NULL)
    {
      root=new node(data);
      return ;
    }
    else
    {
      node *parent=NULL, *curr=dummy;
      while(curr!=NULL)
      {
        parent=curr;
        if(curr->key==data)
        {
          cout<<"\nNUMBER ALREADY EXSIST\n";
          cout<<endl;
          return;
        }
        if(curr->key>data)  curr=curr->left;
        else curr=curr->right;
      }
      if(data>parent->key) parent->right=new node(data);
      else parent->left=new node(data);
    }
  }
  void search(int data)
  {
    search_bst(root,data);
  }
  void search_bst(node *dummy, int data)              //Search Function of BST
  {
    if( root==NULL )
    {
      cout<<"\nNO TREE FORMED YET\n";
      return ;
    }
    while(dummy!=NULL)
    {
      if(dummy->key==data)
      {
        cout<<"\nFOUND";
        return;
      }
      else if(dummy->key > data) dummy=dummy->left;
      else dummy=dummy->right;
    }
    cout<<"\nNO SUCH ELEMENT FOUND \n";
  }
  void delete_node(int data)
  {
    if(root==NULL)
    {
      cout<<"\nNO TREE AVAILABLE\n";
      return;
    }
    node *root1 =del(root,data);
    if(root1==NULL) cout<<"\nNO SUCH ELEMENT FOUND \n";
    else
    {
      root=root1;
      cout<<"\nDELETED SUCCESSFULLY\n";
    }
  }
  node* successor(node* curr)   //Succesor node of Delete operation Function of BST
  {
    curr=curr->right;
    while( curr != NULL && curr->left != NULL )
    {
      curr=curr->left;
    }
    return curr;
  }
  node* del(node* dummy, int data)      //Delete Function of BST
  {
      if(dummy == NULL) return NULL;
      if(dummy->key > data) dummy->left=del(dummy->left,data);
      else if(dummy->key < data )dummy->right=del(dummy->right,data);
      else        //if we find node to be deleted
      {
        if( dummy->left == NULL )
        {
          node*temp=dummy->right;
          delete dummy;
          return temp;
        }
        else if( dummy->right == NULL )
        {
          node* temp=dummy->left;
          delete dummy;
          return temp;
        }
        else
        {
          node*succ= successor(dummy);
          dummy->key=succ->key;
          dummy->right=del(dummy->right,succ->key);
        }
        return dummy;
      }
  }
  void display()
  {
    if(root==NULL)
    {
      cout<<"NO TREE AVAILABLE\n";
      return;
    }
    display_inorder(root);
  }
  void display_inorder(node *dummy)     //Inodrder Dispaly BST (recursive)
  {
    if(dummy==NULL) return;
    display_inorder(dummy->left);
    cout<<dummy->key<<" ";
    display_inorder(dummy->right);
  }
  void mirror_main()
  {
    if(root==NULL)
    {
      cout<<"NO TREE AVAILABLE\n";
      return;
    }
    node *root1=mirror(root);
    display_inorder(root1);
  }
  node* mirror(node * dummy)           //mirror image of BST (REVERSE FUNCTION)
  {
    if(root==NULL)
    {
        cout<<"\nNO TREE AVAILABLE\n";
        return NULL;
    }
    if(dummy==NULL) return NULL;
    node*p=new node(dummy->key);
    p->left=mirror(dummy->right);
    p->right=mirror(dummy->left);
    return p;
  }
  void find_max()                 //Find maximum Function
  {
    if(root==NULL)
    {
      cout<<"\nNO TREE AVAILABLE\n";
      return;
    }
    node*dummy=root;
    while(dummy->right!=NULL)
    {
      dummy=dummy->right;
    }
    cout<<"\nTHE MAX IN BINARY TREE IS :"<<dummy->key<<endl;
  }
  void find_min()         //Find Minimum Function of BST
  {
    if(root==NULL)
    {
      cout<<"\nNO TREE AVAILABLE\n";
      return;
    }
    node*dummy=root;
    while(dummy->left!=NULL)
    {
      dummy=dummy->left;
    }
    cout<<"\nTHE MINIMUM IN BINARY TREE IS :"<<dummy->key<<endl;
  }
  void display_wise()         //Level Order traversal (Using Queue STL)
  {
    if(root==NULL)
    {
      cout<<"\nNO TREE AVAILABLE\n";
      return ;
    }
    node* dummy=root;
    queue<node*> q;
    q.push(root);
    cout<<"\nLEVEL WISE TRAVERSAL OF BST IS :";
    while(!q.empty())
    {
      cout<<q.front()->key<<" ";
      if(q.front()->left!=NULL) q.push(q.front()->left);
      if(q.front()->right!=NULL) q.push(q.front()->right);
      q.pop();
    }

  }
}obj;
//---------------------------------MAIN FUNCTION----------------------------
int main()
{
  int choice=-1;

  while(choice !=9)
  {
    int n=-1,m;
    cout<<"\n------------------------------------------------MENU---------------------------------\n";
    cout<<endl;
    cout<<"\nENTER YOUR CHOICE\n1.INSERT\n2.SEARCH\n3.DELETE\n4.DISPLAY\n5.MIRROR\n6.FIND MAXIMUM\n7.FIND MINIMUM\n8.LEVEL ORDER DISPLAY\n9.EXIT\n";
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
        while(n!=0)
        {
          cout<<"ENTER NUMBER YOU WANT TO INSERT IN BST :";
          cin>>m;
          obj.insert_main(m);
          cout<<"WANT TO CONITNUE (0 to exit): ";
          cin>>n;
        }
        cout<<"\nSUCCESSFULLY ENTERED ALL THE NUMBERS "<<endl;
        break;
      }
      case 2:
      {
          cout<<"\nENTER THE NUMBER YOU WANT TO SEARCH :";
          cin>>m;
          obj.search(m);
          break;
      }
      case 3:
      {
        cout<<"\nENTER THE NUMBER YOU WANT TO DELETE :";
        cin>>m;
        obj.delete_node(m);
        break;
      }
      case 4:
      {
        cout<<"\nTHE INORDER DISPLAY OF BST IS :";
        obj.display();
        break;
      }
      case 5:
      {
        cout<<"\nTHE MIRROR IMAGE OF BST IS :";
        obj.mirror_main();
        break;
      }
      case 6:
      {
        obj.find_max();
        break;
      }
      case 7:
      {
        obj.find_min();
        break;
      }
      case 8:
      {
        obj.display_wise();
        break;
      }
      case 9: break;
      default : cout<<"\nENTER RIGHT CHOICE SIR...WE DON'T HAVE TIME TO WASTE !\n";
    }
  }
  return 0;
}
