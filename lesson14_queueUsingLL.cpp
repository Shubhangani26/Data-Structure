#include<iostream>
using namespace std;
class node{
    public:
      node* next;
      int data;
      node(int val){
        data = val;
        next =NULL;
    }
    
};
class queue{
    node* front;
    node* back;
    public:
    queue(){
        front = NULL;
        back = NULL;
    }
    void enqueue(int x){
        node* n = new node(x);
        if (front == NULL){
             back = n;
            front = n;
        }
        back->next = n;
        back = n;
    }
    void dequeue(){
        if(front == NULL || front>back){
            cout<<"Queue is empty ";
        }
        if(front==back){
            front = back = NULL;
        }
        node *todelete = front;
        front= front->next;
        delete todelete;
    }
    int peek(){
        if(front == NULL || front>back){
            cout<<"Queue is empty ";
        }
        return front->data;
    }
    bool isEmpty(){
        if(front == NULL || front>back){
            cout<<"Queue is empty ";
            return true;
        }
        else
         return false;
    }
    void display(){
        if(front == NULL|| front>back){
            cout<<"empty";
        }
        node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


};
int main(){
    queue q;
    q.enqueue(2);
    q.enqueue(9);
    q.enqueue(5);
    q.enqueue(3);
    q.display();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    return 0;
}