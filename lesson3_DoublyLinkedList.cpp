#include <iostream>
using namespace std;
class node{
    public:
     int data;
     node* next;
     node* prev;
    node(int val){
        data = val;
        next=NULL;
        prev=NULL;
    }
    ~node(){
        int val = this->data;
        if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
     cout<<"Memory is free for node with data "<<val<<endl;
}
}
void addToHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    
    //n->prev is pointing to null bcz of constructor therefore we dont need to specify it
    if(head!=NULL)
    {
        head->prev= n;
    }
    head= n;
}
void addToTail(node* &head,int val){
    node* n = new node(val);
    node* temp=head;
    if(head==NULL){
        addToHead(head,val);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
    n->prev=temp;      
    //n->next is pointing to null bcz of constructor therefore we dont need to specify it
}
void addToPos(int val ,node* &head, int index){
    node* n = new node(val);
    if(index==0){
       addToHead(head,val);
       return;
    }
    node* temp = head; //pointer
    for(int i = 0;i<(index-1);i++){
        temp=temp->next;
    }
    n->next=temp->next;   // temp is the previous node of new node which we have to insert n
    temp->next=n;
    n->prev=temp;
}
void deleteHead(node* head){
    if(head==NULL){
        return;
    }
   node* deletenode = head;
   head=head->next;
   head->prev=NULL;
   return;
   delete deletenode; 
    
}
void deleteVal(node* head,int pos){
    node* temp = head;
    int count=1;
    if(head==NULL){
        deleteHead(head);
        return;
    }
    while(temp!=NULL&& count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next; // temp ke previous ka next vale part m hum temp ka jo next h voh rkhe ge
    temp->next->prev=temp->prev;
    delete temp;
}
void deleteTail(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* deletenode = temp->next;
    temp->next=NULL;
    delete deletenode;
    
}
node* reverse(node* head){
   node* prevptr = NULL;
   node* currentptr = head;
   node* nextptr;
   while(currentptr!= NULL) {
     prevptr= currentptr->prev;
     nextptr = currentptr->next;
     
     currentptr->prev=nextptr;
     currentptr->next=prevptr;

     currentptr= currentptr->prev; 
   }
   if (prevptr!=NULL)
      prevptr = prevptr->prev;// loop ends just because currentptr == null
   return prevptr;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;       
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    addToHead(head,6);
    addToHead(head,1);
    addToHead(head,0);
    display(head);
    addToTail(head,8);
    addToTail(head,2);
    addToTail(head,6);
    display(head);
    cout<<endl;
    cout<<"REVERSING"<<endl;
    node* newhead = reverse(head);
    display(newhead);
    cout<<endl;

    addToPos(9,head,0);
    display(head);
    // deleteTail(head);
    // display(head);
    
    // deleteVal(head,3);
    // display(head);
    deleteHead(head);
    display(head);
    return 0;
}