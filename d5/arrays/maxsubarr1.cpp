#include<iostream>
#include <climits>
using namespace std;
//kedans algorithm
int main(){
    int n=5;
    int arr[n]={2,-3,5,-6,3};
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        maxsum=max(currsum,maxsum);
        if(currsum<0){
            currsum=0;
        }
    }
    cout<<maxsum;
    return 0;
    
}