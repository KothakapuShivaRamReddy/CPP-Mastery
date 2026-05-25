// this code is to find the K nearby cars to the origin(0,0) given the positions of the cars in a 2D plane
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Car{
 public:
   int idx;
   int distsq;

   Car(int idx,int distsq){
    this->idx=idx;
    this->distsq=distsq;
   }

   bool operator <(const Car &obj) const{
    return this->distsq>obj.distsq;//minheap
   }
};
void nearbyCars(vector<pair<int,int>> &pos,int K){
    vector<Car> cars;

    for(int i=0;i<pos.size();i++){//O(n)
        int distsq=(pos[i].first*pos[i].first) +(pos[i].second*pos[i].second);
        cars.push_back(Car(i,distsq));
    }

    priority_queue<Car> pq(cars.begin(),cars.end());//O(n);

    //for(int i=0 to n-1)  pq.push(car[i])  //O(nlogn)

    for(int i=0;i<K;i++){ //O(k)
        cout<<"car:"<<pq.top().idx<<endl;
        pq.pop();
    }
}

int main(){
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int K=2;
    nearbyCars(pos,K);
    // car:0
    // car:2
}