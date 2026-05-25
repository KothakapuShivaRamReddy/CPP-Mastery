// this code is to find the maximum in each sliding window of size k in the given array
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 void slidingWindowMax(vector<int> &arr,int k){
    priority_queue<pair<int,int>> pq;//max heap is built in c++ by default when we use pair then it will compare first element of pair and if they are same then it will compare second element of pair
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push(make_pair(arr[i],i));
    }

     cout<<"output:"<<pq.top().first<<" ";//3
    for(int i=k;i<arr.size();i++){
        while(!pq.empty() && pq.top().second<=i-k){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        // if(i>=k-1){
        //     ans.push_back(pq.top().first);
        // }
            cout<<pq.top().first<<" ";//3 3 5 6 7
    }

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";//3 3 5 6 7
    // }
}
int main(){
    vector<int> arr={1,3,-1,-3,5,3,6,7};
    int k=3;
    slidingWindowMax(arr,k);
}
//output:3 3 5 5 6 7 