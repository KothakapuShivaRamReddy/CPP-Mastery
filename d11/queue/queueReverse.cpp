#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){//pass by reference changes in fnx changes in main also after function call also
     stack<int> s;
     while(!q.empty()){
        s.push(q.front());
        q.pop();
     }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main(){
    queue<int> q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }

    reverse(q);
    while(!q.empty()){
        cout<<q.front()<<" ";//5 4 3 2 1 
        q.pop();
    }
    return 0;
}