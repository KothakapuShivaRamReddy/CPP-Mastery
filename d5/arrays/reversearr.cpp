#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int left=0;
    int right=n-1;
    while(left<=right){
        swap(arr[left],arr[right]);
        left++;
        right--;


    }

   for(int i=0;i<n;i++){
      cout<<arr[i]<<endl;
      
   }
 return 0;


}