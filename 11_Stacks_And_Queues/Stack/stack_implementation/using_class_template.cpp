#include<iostream>
#include<vector>
using namespace std;
template<class T>//class template we can use any name instead of T but it is a convention to use T for template class
class Stack{
    vector<T> v;//we can use any data type in the stack by using template class and we can create stack of int, char, float, double etc. by using template class
    public:
      void push(T val){
        v.push_back(val);
      }
      void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return;
        }
        v.pop_back();
      }
      T top(){
        // if(isEmpty()){
        //     cout<<"Stack is Empty\n";
        //     return -1;
        // }
       int idx=v.size()-1;
       return v[idx];
      }
      bool isEmpty(){
        return v.size()==0;
      }
};

int main(){
    Stack<int> s;//we can create stack of int by using template class and we can create stack of char, float, double etc. by using template class
    
    s.push(1);
    s.push(2);
    s.push(3);


    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


    Stack<char> s1;//we can create stack of char by using template class and we can create stack of int, float, double etc. by using template class
    
    s1.push('a');
    s1.push('b');
    s1.push('c');

    while(!s1.isEmpty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return 0;
}

// 3 2 1 
// c b a 