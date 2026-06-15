#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;


int LIS(vector<int> arr){
    unordered_set<int> s(arr.begin(),arr.end());

    vector<int> arr1(s.begin(),s.end());
    sort(arr1.begin(),arr1.end());


    //LCS=> LIS
    int n=arr.size();
    int m=arr1.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(arr[i-1]==arr1[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
   vector<int> arr={50,3,10,7,40,80};
   cout<<LIS(arr);

    return 0;
}