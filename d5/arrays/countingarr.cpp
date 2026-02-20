#include<iostream>
#include<climits>
using namespace std;

int main(){
    int minval=INT_MAX,maxval=INT_MIN;
    int freq[100]={0};
    int arr[]={1,3,4,1,3,4,9,4};
    int n=sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        minval=min(minval,arr[i]);
        maxval=max(maxval,arr[i]);
    }
    for(int i=0;i<n;i++){
       freq[arr[i]]++;
      
    }
    //  for(int i=0;i<n;i++){
    //     cout<<freq[i];
    // }
    int j=0;
    for(int i=minval;i<=maxval;i++){
           while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
           } 
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
// 8
// 020230001
// 1
// 3
// 3
// 4
// 4
// 4
// 9