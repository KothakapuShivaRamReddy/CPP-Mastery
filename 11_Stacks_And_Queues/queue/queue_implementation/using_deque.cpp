#include<iostream>
#include<deque>
using namespace std;
class Queue{
    deque<int> deq;
public:
   void push(int data){
        deq.push_back(data);
   }
   void pop(){
       deq.pop_front();
   }
   int front(){
    return deq.front();
   }

};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);//1 2 3
    cout<<q.front()<<endl;//1
    q.pop();//2 3 
    cout<<q.front()<<endl;//2

    
    return 0;
}