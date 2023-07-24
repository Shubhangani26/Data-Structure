#include<iostream>
using namespace std;

class node{
   public :
   int data;
   node* next;

   node(int val){
    data=val;
    next=NULL;
   }
   ~node(){
    int val = this->data;
    if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
     cout<<"Memory is free for node with data "<<val<<endl;
   }
};
void addToHead(node* &head,int val){
   node* n = new node(val);
   n->next = head;
   node* temp = head;
   if(head==NULL){
    n->next=n;
    head=n;
    return;
   }
   while(temp->next!= head){
    temp=temp->next;
   }
   temp->next=n;
   n->next=head;
   head=n;
}
void addToTail(node* &head,int val){
    node* n = new node(val);
    if (head==NULL){
        addToHead(head,val);
        return;
    }
    node* temp = head;
    while(temp->next!=head){
      temp=temp->next;
    }
    temp->next=n;
    n->next=head;

}
void addTopos(int val,node* &head,int index){
    node* n = new node(val);
    if(index==0){
        addToHead(head,val);
        return;
    }
    node*temp = head;
    for(int i =0;i<(index-1);i++){
       temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
void deleteHead(node* &head){
    node*temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* deleteNode=head;
    temp->next=head->next;
    head= head->next;
    delete deleteNode;
}
void deletePos(node* &head,int pos){
    node* temp=head;
    int count= 1;
    if(pos==0){
        deleteHead(head);
        return;
    } 
    while(count!= pos){
        temp=temp->next;
        count++;
    }
    node* deleteNode = temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
}
void deleteTail(node* & head){
    node* temp= head;
    if(head==NULL){
        deleteHead(head);
        return;
    }
    while(temp->next->next!=head){
        temp=temp->next;
    }
    node* deleteNode =temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
    

}

void display(node* &head){
    node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    while(temp!=head);
    cout<<endl;
} 
int main(){
    node* head = NULL;
    addToHead(head,2);
    addToHead(head,8);
    addToHead(head,3);
    display(head);
    addToTail(head,0);
    addToTail(head,5);
    addToTail(head,1);
    display(head);
    addTopos(6,head,3);
    display(head);
    // deleteHead(head);
    // display(head);
    // deletePos(head,3);
    // display(head);
    deleteTail(head);
    display(head);
    return 0;
}