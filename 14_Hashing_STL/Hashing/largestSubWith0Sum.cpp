//Largest sub array with sum 0
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int largestSubWith0Sum(vector<int> arr){//sum[i,j]=sum[j]-sum[i-1]//sum[j]=sum[i-1]//sum[i-1] is the sum of subarray which we want to find
    unordered_map<int,int> m;//sum idx;
    int ans=0;
    int sum=0;

    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        if(m.count(sum)){
            int currLen=j-m[sum];//j-idx;//currLen is the length of subarray with sum 0
            ans=max(ans,currLen);
        }else{
            m[sum]=j;
        }
    }

    return ans;
}

int main(){

    vector<int> arr={15,-2,2,-8,1,7,10};


    cout<<"largest sub array with sum 0:"<<largestSubWith0Sum(arr);

    return 0;
}

//largest sub array with sum 0:5