#include<iostream>
using namespace std;
class node{
    public:
      node*left;
      node*right;
      int info;
}
*root = NULL; //global
class bst{
    node *p, *q, *p1;
    public :
    void insert();
    void iterative_inorder(node*);
    void iterative_preorder(node*);
    void iterative_postorder(node*);
};
void bst :: insert(){
  int i;
  cout<<"Enter a node value : ";
  cin>>i;
  while(i!= 0){
  if(root == NULL){
    root = new node;
    root->left = 0 ; root->right=0;
    root->info=i;
  }
  else{
    p = root;
    q= new node;
    q->left=0;q->right=0;
    q->info=i;
    while(p!=0){
    if(i< p->info){
        p1=p;
        p = p->left;
    }
    else{
        p1 = p;
        p = p->right;
    }
  }
  }
  if (i<p1->info){
    p1->left=q;
  }
  else{
    p1->right=q;
  }
  cout<<"enter new node : ";
  cin>>i;
  }
  
}
void bst :: iterative_inorder(node*){
    if(root==NULL){
        return;
    }
    else{
        iterative_inorder(root->left);
        cout<<root->info;
        iterative_inorder(root->right);
    }
}
int main(){
    bst b;
   node *root = NULL;
    b.insert();
    b.iterative_inorder(root);
    return 0;
}