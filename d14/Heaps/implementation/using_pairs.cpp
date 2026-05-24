#include<iostream>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(const pair<string,int> &p1,const pair<string,int> &p2){
        return p1.second<p2.second;//for max heap
        //return p1.second>p2.second;//for min heap
    }
};

int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
    pq.push({"A",90}); 

    pq.push({"B",80});
    pq.push({"C",95});
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
}