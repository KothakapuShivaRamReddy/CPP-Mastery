#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxActivities(vector<int> start, vector<int> end ){
    int count=1;
    int currEndTime=end[0];
    for(int i=1;i<start.size();i++){
        if(start[i]>=currEndTime){
            count++;
            currEndTime=end[i];
        }
    }
    return count;
}

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second; 
}

int main(){
    // vector<int> start={1,3,0,5,8,5};
    // vector<int> end={2,4,6,7,9,9};
    vector<int> start={0,1,2};
    vector<int> end={9,2,4};
    vector<pair<int,int>> activity(3,make_pair(0,0));
    activity[0]=make_pair(0,9);
    activity[1]=make_pair(1,2);
    activity[2]=make_pair(2,4);

    for(int i=0;i<activity.size();i++){
        cout<<"A"<<i<<":"<<activity[i].first<<","<<activity[i].second<<endl;
    }

    sort(activity.begin(),activity.end(),compare);//custom fnx to compare
    cout<<"-------sorted------\n";
    for(int j=0;j<activity.size();j++){
        cout<<"A"<<j<<":"<<activity[j].first<<","<<activity[j].second<<endl;
    }
   
    return 0;
}

// A0:0,9
// A1:1,2
// A2:2,4
// -------sorted------
// A0:1,2
// A1:2,4
// A2:0,9