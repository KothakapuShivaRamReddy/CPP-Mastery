#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}
int maxProfit(vector<pair<int,int>> jobs){
    int n=jobs.size();

    sort(jobs.begin(),jobs.end(),compare);
    int maxprofit=jobs[0].second;
    int safeDeadline=1;
    
    for(int i=1;i<n;i++){
        if(jobs[i].first>safeDeadline){
            maxprofit+=jobs[i].second;
            safeDeadline++;
        }
    }
    return maxprofit;
}

int main(){
    int n=4;
    
    vector<pair<int,int>> jobs(n,make_pair(0,0));
    jobs[0]=make_pair(4,20);
    jobs[1]=make_pair(1,10);
    jobs[2]=make_pair(1,40);
    jobs[3]=make_pair(1,30);
    // jobs[3]=make_pair(2,30);
   
     cout<< "max profit :"<<maxProfit(jobs);

    return 0;

}