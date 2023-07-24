#include<iostream>
using namespace std;
const int size = 5;
class circular{
    int a[size];
    int front;
    int rare;
    public:
    circular(){
        front = -1;
        rare = -1;
    }
    void enqueue(int x){
        if (front==-1 && rare == -1){
            front++;
            rare++;
            a[rare]=x;
        }
       else if (((rare+1)%size)==front){
        cout<<"Queue is full ";
       }
       else
        rare = ((rare+1)%size); //this how we will increment rare here(we do so bcz it is circular if rare index is 4 then by doing this it will become 0 instead of becoming 5 and therefore we can insert element in empty index 0)
        a[rare]=x;
    }
    void dequeue(){
        if(front==-1 && rare==-1){
            cout<<"Queue is empty (underflow) ";
        }
        else if(front == rare ){ // ie queue has only one element 
            front=rare=-1;
        }
        else{
            front = (front+1)%size; //this how we will increment front here(we do so bcz it is circular if front index is 4 then by doing this it will become 0 instead of becoming 5)
        }
    }
    int peek(){
        if(front==-1 && rare==-1){
            cout<<"queue is empty ";
        }
        else
        return a[front];
    }
    bool isEmpty(){
        if(front==-1 && rare == -1){
            return true;
        }
        else
          return false;
    }
    bool isFull(){
        if((front==0 && rare== size -1)||((rare+1)%size==front)){
            return true;
        }
        else false;
    }
    void display(){
       if(front==-1 && rare==-1){
        cout<<"queue is empty ";
       }
       else{
        int i = front;
        cout<<"Print queue : "<<endl;
          while(i != rare){
            cout<<a[i]<<" ";
            i=(i+1)%size;
          }
          cout<<a[rare]<<" ";
       }
    }
};
 
int main(){
    circular c;
    c.enqueue(5);
    c.enqueue(1);
    c.enqueue(7);
    c.enqueue(2);
    c.enqueue(0);
    c.display();
    cout<<endl<<c.isFull();
    cout<<endl<<"front element of queue is : "<<c.peek()<<endl;
    c.dequeue();
    cout<<endl<<"front element of queue after deleting some elements is : "<<c.peek()<<endl;    
    c.dequeue();
    c.dequeue();
    c.dequeue();
    c.dequeue();
    cout<<endl<<c.isEmpty();
    return 0;
}