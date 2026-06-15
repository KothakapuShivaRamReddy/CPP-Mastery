#include<iostream>
using namespace std;
int search(int arr[],int st,int ei,int target){

    int mid=st+(ei-st)/2;
    if(arr[mid]==target){
        return mid;
    }

    if(arr[st]<=arr[mid]){
       if(arr[st]<=target && target<=arr[mid]){  //>= or > //>= not required
             
        return search(arr,st,mid-1,target);//left
       }else{
           return search(arr,mid+1,ei,target);  //right
       }
    }else{
        if(arr[mid]<=target && target<=arr[ei]){
            return search(arr,mid+1,ei,target);//right
        }else{
            return search(arr,st,mid-1,target);//left
        }

    }
}
int main(){
   int arr[7]={4,5,6,7,0,1,2};
   int n=7;

   cout<<"Idx:"<<search(arr,0,n-1,7)<<endl;
    cout<<"Idx:"<<search(arr,0,n-1,2);

    return 0;
}