#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int countDistinct(vector<int> arr){
    unordered_set<int> s;
    for(int x:arr){
        s.insert(x);    
    }

    for(int x:s){
        cout<<x<<" ";
    }
    cout<<endl;
    return s.size();

}

int main(){
    vector<int> arr={4,3,2,5,6,7,3,4,2,1};

    cout<<"Number of distinct elements in the array is: "<<countDistinct(arr)<<endl;
}