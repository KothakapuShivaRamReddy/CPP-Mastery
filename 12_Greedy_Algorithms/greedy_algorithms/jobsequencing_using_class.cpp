// Job sequencing problem using class 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx,int deadline,int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
    }   
};



int maxProfit(vector<pair<int,int>> pairs){
    int n=pairs.size();
    vector<Job> jobs;

    for(int i=0;i<n;i++){
        //emplace_back is used to construct the object in place without copying or moving it, which can be more efficient than push_back in certain cases.
        //which automatically forwards the arguments to the constructor of the Job class, creating a new Job object directly in the vector without needing to create a temporary object first.
         jobs.emplace_back(i,pairs[i].first,pairs[i].second);//idx,deadline,profit
    }
    sort(jobs.begin(),jobs.end(),[](Job& a,const Job& b){
        return a.profit>b.profit;//sort in decreasing order of profit
    });
    cout<<"selcted jobs are:\n";
    int maxprofit=jobs[0].profit;
    int safeDeadline=1;
    cout<<"selecting job J"<<jobs[0].idx<<endl;

    for(int i=1;i<n;i++){
        if(jobs[i].deadline>safeDeadline){
            cout<<"selecting job J"<<jobs[i].idx<<endl;
            maxprofit+=jobs[i].profit;
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
    // jobs[3]=make_pair(1,30);
    jobs[3]=make_pair(2,30);
   
     cout<< "max profit :"<<maxProfit(jobs);

    return 0;

}
