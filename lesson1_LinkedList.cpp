#include <iostream>
using namespace std;

class node {
    public :
    int data;
    node* next;

    node(int val){  // this constructor we make just to assign the value of node
        data = val;
        next = NULL;
    }
};

void print(node* head){  
    node* temp = head;  //we make pointer and assign head  because if we dont do so then head will change again n again n 
    while(temp != NULL ){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main (){
    node* Firstnode  = new node(2);  // through this we made new node whose val =2 or data = 2 its bcz of parameter constructor
    node* Secondnode = new node(1);
    node* Thirdnode  = new node(7);
    node* Fourthnode = new node(9);
    node* Fifthnode  = new node(5);
    Firstnode->next  =Secondnode;
    Secondnode->next= Thirdnode;
    Thirdnode->next  =Fourthnode;
    Fourthnode->next =Fifthnode;
    print(Firstnode);   // this will print the LL
}