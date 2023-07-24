#include<iostream>
using namespace std;
class stack{
    int s[5];
    int top;
    public:
     stack(){
        top = -1;
     }
     void push(int);
     int pop();
     void display();
};
void stack :: push(int items){
if (top == 4){
    cout<<"stack is full";
}
else{
    top++;
    s[top]=items;
}
}
int stack :: pop(){
    int item;
    if(top==-1){
         cout<<"stack is empty ";
    }
    else{
        top--;
        s[top]=item;
        return item;
    }
}
void stack:: display(){
    if(top==-1){
        cout<<"stack hasno elements ";
    }
    cout<<"the elements are : ";
    for (int i = 4 ;i>=0;i--){
        cout<<s[i]<<" ";
    }
}
int main(){
    stack ob;
    ob.push(2);
    ob.push(7);
    ob.push(1);
    ob.push(5);
    ob.push(0);
    ob.push(9);
    ob.pop();
    ob.display();
    return 0;
}