#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> v;
    public:
      void push(int val){
        v.push_back(val);
      }
      void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return;
        }
        v.pop_back();
      }
      int top(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return -1;
        }
       int idx=v.size()-1;
       return v[idx];
      }
      bool isEmpty(){
        return v.size()==0;
      }
};

int main(){
    Stack s;
    // s.pop();
    // s.top();
    s.push(1);
    s.push(2);
    s.push(3);


    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}