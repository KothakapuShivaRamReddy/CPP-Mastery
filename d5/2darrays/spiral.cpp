//spiral matrix
#include<iostream>
using namespace std;

void spiralmatrix(int arr[3][4],int n,int m){
     int sr=0,sc=0,er=n-1,ec=m-1;
     while (sr <= er && sc <= ec) {
     for(int i=sc;i<=ec;i++){
        cout<<arr[sr][i];
       
     } sr++;
     for(int i=sr;i<=er;i++){
      if(sr==er){
         break;
      }
        cout<<arr[i][ec];
       
     } ec--;
       for(int i=ec;i>=sc;i--){
         if(sc==ec){
            break;
         }
        cout<<arr[er][i];
       
     } er--;
     for(int i=er;i>=sr;i--){
        cout<<arr[i][sc];
     }sc++;
}
}

int main(){
   int arr[4][4]={{1,2,3,4},
               {5,6,7,8},
               {9,10,11,12},
               };
    spiralmatrix(arr,3,4);
    
    return 0;           
}

// 12348121615141395671110