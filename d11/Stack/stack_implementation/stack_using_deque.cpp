#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> deq;
public:
    void push(int data){
        deq.push_back(data);
    }
    void pop(){
        deq.pop_back();
    }
    int top(){
        return deq.back();
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);//1 2 3
    for(int i=1;i<=3;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    // cout<<s.top()<<endl;//1
    // s.pop();//2 3 
    // cout<<s.top()<<endl;//2
    return 0;
}