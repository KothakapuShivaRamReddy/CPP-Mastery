#include<iostream>
using namespace std;

int partition(int arr[],int st,int ei){
    int i=st-1;
    int pivot=arr[ei];
    for(int j=st;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;

}

void quicksort(int arr[],int st,int ei){
    if(st>=ei){
        return;
    }
    int pivotidx=partition(arr,st,ei);

    quicksort(arr,st,pivotidx-1);
    quicksort(arr,pivotidx+1,ei);


}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
     int arr[6]={6,3,7,5,2,4};
    
    int n=6;

    quicksort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}