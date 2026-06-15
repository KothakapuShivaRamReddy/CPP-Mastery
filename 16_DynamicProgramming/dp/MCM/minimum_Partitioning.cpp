#include<iostream>
#include<vector>
using namespace std;


int getDiff(vector<int> arr){
    int n=arr.size();
    int totalSum=0;
    for(int el:arr){
        totalSum+=el;
    }

    int W=totalSum/2;
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i-1][j-arr[i-1]]);//either we dont take the current element or we take the current element and add it to the best solution for the remaining weight
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int grp1Sum=dp[n][W];
    int grp2Sum=totalSum-grp1Sum;
    return abs(grp1Sum-grp2Sum);
}

int main(){
    vector<int> arr={1,6,11,5};
    

    cout<<getDiff(arr);//1
    return 0;
}