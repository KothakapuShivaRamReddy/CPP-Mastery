// longest common substring
#include<iostream>
#include<vector>
using namespace std;
//tabulation
int longestCommonSubstring(string str1,string str2){
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}
int main(){
    string str1="abcde";
    string str2="adcde";
    cout<<longestCommonSubstring(str1,str2)<<endl;//3  cde

    return 0;
}

// 0 0 0 0 0 0 
// 0 1 0 0 0 0 
// 0 0 0 0 0 0 
// 0 0 0 1 0 0 
// 0 0 1 0 2 0 
// 0 0 0 0 0 3 
// 3