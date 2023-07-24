#include<iostream>
using namespace std;

class node {
    public :
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
//     ~node(){
//         int value = this->data;
//         if(this->next!=NULL){
//         delete next;
//         this->next=NULL;
//     }
//     cout<<"Memory is free for node with data "<<value<<endl;
// };
void add_to_head(node* &head,int val){
  node* n = new node(val);
  n->next = head;
  head = n;
  if(head == NULL){
    head = n;
  
  }
}
void insert(int val,node* &head,int index){ // int position = where we insert
    node* n = new node(val); // making node which we will insert
    if(index == 0){
        n->next = head;
        head = n;
        return;     
    }
    
    node* prev = head; //previous node
    for(int i = 0; i<(index-1);i++){
        prev = prev->next;
    }
    n->next= prev->next;  // we have to write it in this order only otherwise we will loss the link
    prev->next=n;
    
}
void add_to_end(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head = n;
    }
    node* temp = head; // we make pointer and assign it as a head because we cant modify head directly if we so then head will get lost 
    while (temp->next!=NULL){
        temp =temp->next;
    }
    temp->next=n;
}
void deleteHead(node* &head){
    node* deleteNode = head;
    head = head->next;
    if(head==NULL){
        return;
    }
    delete deleteNode;
    }
void deleteVal(node* &head,int val){
    node* temp = head;
    if(head== NULL){
        return;
    }
    if(head->next==NULL){
       deleteHead(head);
       return;
    }
    
    while(temp->next->data!=val){  
        temp=temp->next;
    }
    
    node* deleteNode = temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
    
}
bool search(node* &head,key){
    node* temp = head;
    while(temp!=0){
       if(temp->data == val){
        return true;
       }
       temp = temp->next;
    }
    return false;
}
node* reverse(node* &head ){
    node* prevptr  = NULL;
    node* currentptr  = head;
    node* nextptr ;
    while(currentptr!=NULL){
        nextptr  = currentptr->next ;
        currentptr->next =prevptr ;
        
        prevptr  = currentptr ;
        currentptr =nextptr; 
    }
    return prevptr;
}

void display( node* temp){
    int count = 0;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
        count++;
    }
    cout<<"NULL"<<endl;
    cout<<"total elements in the linked list : "<<count<<endl;
}

int main(){
   node* head = NULL;
   add_to_head(head,2);
   add_to_head(head,1);
   add_to_head(head,7);
   add_to_head(head,9);
   display(head);

   cout<<"REVERSING"<<endl;
   node* newhead =  reverse(head);
   display(newhead);

   display(head);
   add_to_end(head,0);
   add_to_end(head,8);
   add_to_end(head,3);
   display(head);
   
   insert(12,head,5);
   //deleteHead(head);
   deleteVal(head,8);// 8 will be delete from linindex
   display(head);

}
