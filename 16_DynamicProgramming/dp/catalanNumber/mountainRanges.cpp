#include<iostream>
#include<vector>
using namespace std;

int mountainRanges(int pairs){
    vector<int> dp(pairs+1,0);
    dp[0]=dp[1]=1;

    for(int i=2;i<pairs+1;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[pairs];
}

int main(){
     int pairs=4;

     cout<<mountainRanges(pairs);//14

    return 0;

}