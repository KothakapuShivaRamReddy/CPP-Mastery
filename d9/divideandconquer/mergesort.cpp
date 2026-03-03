#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int st,int ei,int mid){//O(n)
    vector<int> temp;
    int i=st;
    int j=mid+1;
    while(i<=mid&& j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
        
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    for(int idx=st,x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
    }


}



void mergesort(int arr[],int st,int ei){ //O(log(n))
       if(st>=ei){
        return;
       }
    
       int mid=st+(ei-st)/2;
       mergesort(arr,st,mid);
       mergesort(arr,mid+1,ei);
       merge(arr,st,ei,mid);
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}



int main(){
    int arr[6]={6,3,7,5,2,4};
    
    int n=6;

    mergesort(arr,0,n-1);

    printarr(arr,n);

    return 0;

}