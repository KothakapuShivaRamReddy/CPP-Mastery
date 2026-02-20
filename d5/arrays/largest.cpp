#include<iostream>
using namespace std;
int main(){
    int arr[]={2,22,3,55,99};
    int n=sizeof(arr)/sizeof(int);
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];

        }if(min>arr[i]){
            min=arr[i];
        }
    }
    cout<<"the largest:"<<max<<endl;
    cout<<"the smallest:"<<min<<endl;

    return 0;

}