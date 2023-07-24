#include<iostream>
using namespace std;
class queue{
    int m;
    int ch;
    int a[5];
    int front;
    int rare;
    public:
    queue(){
        front= -1;
        rare = -1;
    }
    void insert(){
        
        do{
            cout<<"enter a element : ";
            cin>>m;
        if(rare == -1){
          front++;
          rare++;
          a[front]=m;
        }
        else if(rare<5){
            rare++;
            a[rare]=m;
        }
        else{
            cout<<"Queue is full "<<endl;
            cout<<"Continue ??? ";
            cin>>ch;
        }
    }while(ch=='y');
    }
    void del(){
        if(front==-1){
            cout<<"stack is empty: ";
        }
        else if(front<5 && front>-1){
            cout<<"the deleted element is : "<<a[front];
            front++;
        }
        else{
            cout<<"queue is finished : ";
        }
    }
    void display(){
        if(front==-1){
            cout<<"Queue is empty : ";
        }
        else{
            for(int i = front; i<=rare;i++){
                cout<<a[i];
            }
        }
    }
};
int main(){
   queue q;
   q.insert();
   q.display();
   int m;
   
   return 0;
}