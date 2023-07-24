#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }


};

void print(node* head){
    node* ptr = head; 
    while(ptr !=NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }cout<<"NULL\n";
}

int main(){
    
    node* one = new node(4);
    node* two = new node(3);
    node* third = new node(2);

    one->next = two;
    two->next = third;


    print(one);
}