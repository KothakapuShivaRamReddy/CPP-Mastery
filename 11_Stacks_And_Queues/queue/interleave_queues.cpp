// Interleave Two Queues
// Given a queue of integers, interleave the first half of the queue with the second half of the queue.
// If the number of elements in the queue is odd, the extra element should be considered part of the first half of the queue.
// Example: 1 2 3 4 5 6 -> 1 4 2 5 3 6
#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &org){
    int n=org.size();
    queue<int> first;
    for(int i=1;i<=n/2;i++){
        first.push(i);
        org.pop();
    }

    while(!first.empty()){
        org.push(first.front());
       first.pop();
       org.push(org.front());
       org.pop();
    }
}

int main(){
    queue<int> org;
    for(int i=1;i<=10;i++){
        org.push(i);
    }

    interleave(org);
    for(int i=1;i<=10;i++){
        cout<<org.front()<<" ";//1 6 2 7 3 8 4 9 5 10 
        org.pop();
    }
    cout<<endl;

    return 0;

}