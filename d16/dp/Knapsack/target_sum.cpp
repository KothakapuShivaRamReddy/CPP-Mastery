#include<iostream>
#include<vector>
using namespace std;


//initilizing the dp table with 0 because we are using 1 based indexing for dp because of the base case when n=0 or target=0
bool  targetSum(vector<int> nums,int target){
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));//dp[i][j] will be true if we can make the target j using the first i numbers

    for(int i=1;i<=n;i++){//i<=n because we are using 1 based indexing for dp because of the base case when n=0 or target=0
        for(int j=1;j<=target;j++){//j<=target because we are using 1 based indexing for dp because of the base case when n=0 or target=0
            if(nums[i-1]<=j){//
                dp[i][j]=max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j]);//include or exclude the current number
            }else{
                dp[i][j]=dp[i-1][j];//exclude the current number
            }
        }
    }
    return dp[n][target]==target;
}
int main(){
    vector<int> nums={4,2,7,1,3};
    int target=10;


    cout<<targetSum(nums,target)<<endl;
}