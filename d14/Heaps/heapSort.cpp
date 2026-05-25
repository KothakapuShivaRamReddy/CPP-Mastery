#include<iostream>
#include<vector>
using namespace std;

 void Heapify(int i,vector<int> &vec,int n){

        if(i>=vec.size()){
            return;
        }
        int l=2*i+1;
        int r=2*i+2;

        int maxI=i;
        if(l<n && vec[l]>vec[maxI]){//if we want min heap then vec[l]<vec[maxI]
            maxI=l;
        }
        if(r<n && vec[r]>vec[maxI]){// if we want min heap then vec[r]<vec[maxI]
            maxI=r;
        }

        swap(vec[i],vec[maxI]);//swap with the largest element among parent and children
        if(maxI!=i){// if we are swapping then only we need to heapify the child
            Heapify(maxI,vec,n);
        }

    }

void HeapSort(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        Heapify(i,arr,n);
    }
    for(int i=n-1;i>=0;i--){
       swap(arr[0],arr[i]);
       Heapify(0,arr,i);
    }
}
int main(){
    vector<int> arr={1,4,2,5,3};
    
    HeapSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";//1 2 3 4 5 
    }
    return 0;

}