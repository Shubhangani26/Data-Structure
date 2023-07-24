#include<iostream>
using namespace std;
class node{
    public:
      int data;
      node* next;
      node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void addToHead(node* &head,int val){
    node* n = new node(val);
    
    if(head==NULL){
        n->next=head;
        n->prev=head;
        head=n;
        return;
    }
    node* temp = head;
    while(temp!=head){
        temp=temp->next;
    }
        head->prev=n;
        n->next=head;
        head=n;
}

void display(node* &head){
    node*temp = head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    } while(temp!=head);
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    addToHead(head,3);
    addToHead(head,1);
    addToHead(head,9);
    addToHead(head,2);
    display(head);
}