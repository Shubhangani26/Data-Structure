#include<iostream>
using namespace std;
class stack{
    int a[5];
    int top;
    public:
    stack(){
        top = -1;
    }
    void push(int);
    int pop();
    void display();
    bool isEmpty();
};
void stack :: push(int x){
    if(top == 4){
        cout<<"full";
    }
    else{
        top++;
        a[top];
    }
}
int stack:: pop(){
    if(top==-1){
        cout<<"underflow";
    }
    else
      return a[top--];
}
void stack:: display(){
    if(top==-1){
        cout<<"NOTHING";
    }
    else{
        for(int i = top ; i>=0;i--){
            cout<<a[i]<<" ";
             
        }
    }
}
bool stack :: isEmpty(){
    if(top==-1)
     return true;
    else
    return false;
}
int main(){
   stack ob;
   ob.push(8);
   ob.push(0);
   ob.push(9);
   ob.push(3);
   cout<<endl<<ob.pop()<<endl;
    return 0;
}