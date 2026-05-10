#include<iostream>
using namespace std;

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";

    }
    cout<<endl;
}

void changeArr(int arr[],int n,int i){
     if(i==n){
        printArr(arr,n);
        return;
     }
      arr[i]=i+1;//change
      changeArr(arr,n,i+1);//forward
      arr[i]-=2;//backtracking

}


int main(){
    int arr[5]={0};

    changeArr(arr,5,0);//forward
    printArr(arr,5); //backtracking

    return 0;
}
