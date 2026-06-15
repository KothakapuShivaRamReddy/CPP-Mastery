#include<iostream>
#include<vector>
using namespace std;

int fibwithRec(int n){//O(2*n)
    if(n==0||n==1){
        return n;
    }


    return fibwithRec(n-1)+fibwithRec(n-2);
}
//memorization
int fibwithmem(int n,vector<int> &dp){//O(n)
    if(n==0||n==1){
        return  n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=fibwithmem(n-1,dp)+fibwithmem(n-2,dp);
    return dp[n];
}

//tabulation

int fibwithtab(int n){//O(n)
     vector<int> fib(n+1,0);

     fib[0]=0;
     fib[1]=1;

     for(int i=2;i<=n;i++){
         fib[i]=fib[i-1]+fib[i-2];
     }

     return fib[n];
}

int main(){
    int n=6;
    vector<int> dp(n+1,-1);

    cout<<fibwithtab(n);

    return 0;
}