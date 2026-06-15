#include<iostream>
#include<vector>
using namespace std;

int minChange(vector<int> coins, int V){
    int n=coins.size();
    int count=0;
    for(int i=n-1;i>=0 && V>0;i--){
        if(V>=coins[i]){
            count+=V/coins[i] ;//no of coins of that denomination
            V=V%coins[i];//remaining amount to be paid
        }
    }
    return count;
}

int main(){//O(n) and if we use sorting then O(nlogn) time complexity
    vector<int> coins={1,2,5,10,20,50,100,500,2000};//denominations of coins in India(if not sorted, we can sort it and then apply greedy approach)
    int V=590; 

    cout<<"min change coins count is:"<<minChange(coins,V);//5 coins of 100,1 coin of 50,2 coins of 20,2 coins of 10

    return 0;
}