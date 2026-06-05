#include<iostream>
#include<vector>
using namespace std;

int unbounded_knapsack(vector<int> val,vector<int> wt,int W,int n){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
             int itemwt=wt[i-1];
             int itemval=val[i-1];
             if(itemwt<=j){
                //dp[i][j-itemwt small change from 0/1 knapsack because we can include the same item again and j-itemwt because we are including the current item
                dp[i][j]=max(itemval+dp[i][j-itemwt],dp[i-1][j]);//i because we can include the same item again and j-itemwt because we are including the current item
             }
             else{
                dp[i][j]=dp[i-1][j];
             }
        }
    }

     for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
     }
     return dp[n][W];
}

int main(){
   vector<int> val={15,14,10,45,30};
   vector<int> wt={2,5,1,3,4};
   int n=5;
   int W=7;

   cout<<unbounded_knapsack(val,wt,W,n)<<endl;

    return 0;
}