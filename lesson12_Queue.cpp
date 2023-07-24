#include<iostream>
using namespace std;
class queue{
    int* arr;
    int front;
    int rare;
    public:
     queue(){
        front=-1;
        rare = -1;
        arr = new int[5];
    }
    void enqueue(int x){
        if(rare == 4){
            cout<<"queue is full ";
        }
        else{
            rare++;
            arr[rare]= x;
        }
        if (front==-1){
            front++;
            arr[front]= x;
        }
    }
        void dequeue(){
            if(front == -1 || front>rare){
                cout<<"Queue is underflow ";
            }
            else
            front++;
        }
        int peek(){
             if(front == -1 || front>rare){
                cout<<"Queue is underflow ";
                return -1;
        }
             else
               return arr[front++];
              
    }
    void display(){
        if(front == -1 || front>rare){
                cout<<"Queue is empty ";
            }
        else{
         for (int i = front; i<=rare ; i++ )   {
            cout<<arr[i];

        }
        }
    
    }
};
int main(){
    queue q;
    q.enqueue(2);
    q.enqueue(7);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);
    q.display();
    cout<<endl;
    cout<<q.peek();
    cout<<q.peek();
    cout<<q.peek();
    cout<<q.peek();
    cout<<q.peek();
    
    return 0;
}