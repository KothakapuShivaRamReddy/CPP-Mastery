#include<iostream>
using namespace std;
 int main(){
    int n=2,m=3;
    int count=0;
    int arr[n][m]={{4,7,7},{8,7,7}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==7){
                count++;

            }
        }
    }cout<<count<<endl;
    return 0;

 }