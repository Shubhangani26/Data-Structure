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
class stack{
    node* top;
    public :
    stack(){
        top = NULL;
    }
    void push(int val){
        node* n = new node(val);
        if(top==NULL){
          top=n;
        }
        
        top->next = n;
        n=top;
    }
    int pop(){
        if (top==NULL){
            cout<<"empty";
        }
        return top->data;
    }
    bool isEmpty(){
        if(top==NULL)
          return true;
        else 
        return false;
    }
    void display(){
        {
        node* temp = top;
        if(top==NULL){
            cout<<"Empty";
            return;
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        } 
        cout<<endl;
        }
        }
    
};

int main(){
    stack c;
    c.push(3);
    c.push(4);
    c.push(1);
    c.push(9);
    c.display();
}