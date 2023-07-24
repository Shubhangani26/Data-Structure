#include <iostream>
using namespace std;
class queue{
    int a[5];
    int front;
    int back;
    public :
    queue(){
        front = -1;
        back = -1;
    }
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    int peek();   // top
    void display();
};
void queue :: enqueue(int x){
    if(back == 4){
        cout<<"queue is full"<<endl;
    }
    else{
        back ++;
        a[back] = x;
    }
    if(front ==-1 ){
        front++;
      
        a[front]=x;
    }
      
}
void queue :: dequeue(){
    if(front==-1 || front>back){
        cout<<"Queue is empty : "<<endl;
    }
    else
      front++;
}
int queue:: peek(){
    if(front==-1 || front>back){               
        cout<<"Queue is empty : "<<endl;
    }

    return a[front++];
    
}
bool queue:: isEmpty(){
    if(front==-1||front>back){
        return true;
    }
    else 
        return false;
}
void queue:: display(){
    if(front==-1){
      cout<<"NO element";
    }
    else{
        for(int i = front;i<=back;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
queue q;
q.enqueue(2);
q.enqueue(5);
q.enqueue(1);
q.enqueue(7);
q.enqueue(4);
q.display();
cout<<endl<<q.peek()<<endl;
cout<<q.peek()<<endl;
q.dequeue();
q.dequeue();
cout<<q.isEmpty();
 }