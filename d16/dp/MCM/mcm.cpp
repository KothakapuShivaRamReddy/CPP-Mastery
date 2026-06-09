#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int mcmRec(vector<int> arr,int i,int j){
    if(i==j){
        return 0;
    }

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        //(i,k)
        int cost1=mcmRec(arr,i,k);
        //(k+1,j)
        int cost2=mcmRec(arr,k+1,j);
        //curr partion cost
        int currcost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);

        ans=min(ans,currcost);
    }
    return ans;
}

int mcmMem(vector<int> arr,int i,int j,vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        //(i,k)
        int cost1=mcmMem(arr,i,k,dp);
        //(k+1,j)
        int cost2=mcmMem(arr,k+1,j,dp);
        //curr partion cost
        int currcost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);

        ans=min(ans,currcost);
    }
    return dp[i][j]=ans;
}
int mcmTab(vector<int> arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=1;i<n;i++){
        dp[i][i]=0;
    }
    for(int len=2;len<n;len++){//len is the length of the current subproblem
        for(int i=1;i<=n-len;i++){//i is the start index of the current subproblem
            int j=i+len-1;// j is the end index of the current subproblem
            
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){//k is the partition index

                int cost1=dp[i][k];
                int cost2=dp[k+1][j];
                int currcost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
                dp[i][j]=min(dp[i][j],currcost);
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    vector<int> arr={1,2,3,4,3};
    int n=arr.size();
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<mcmTab(arr);//30
    return 0;
}