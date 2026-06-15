//Count of subarrays with sum k
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int  subArrayCountWithK(vector<int> arr,int k){//sum[i,j]=sum[j]-sum[i-1]//sum[j]-k=sum[i-1]
    unordered_map<int,int> m;//sum,count;
    m[0]=1;
    int ans=0;
    int sum=0;

    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        if(m.count(sum-k)){//sum-k exists//sum-k is the sum of subarray which we want to find
            ans+=m[sum-k];
        }

        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum]=1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={10,2,-2,-20,10};

    int k=-10;

    cout<<"Subarray Count:"<<subArrayCountWithK(arr,k);//3
}