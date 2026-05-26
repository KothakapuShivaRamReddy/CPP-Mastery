//Union and Intersection of two arrays
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void printUnion(vector<int> arr1,vector<int> arr2){
    unordered_set<int> s;
    for(int el:arr1){
        s.insert(el);
    }
    for(int el:arr2){
        s.insert(el);
    }
    for(int el:s){
        cout<<el<<" ";
    }
    cout<<endl;
}

void printIntersection(vector<int> arr1,vector<int> arr2){

    unordered_set<int> s;

    for(int el:arr1){
        s.insert(el);
    }
    for(int el:arr2){
        if(s.find(el)!=s.end()){
            cout<<el<<" ";
            s.erase(el);
        }
    }
    cout<<endl;
}

int main(){

    vector<int> arr1={7,3,9};
    vector<int> arr2={6,3,9,2,9,4};
    cout<<"UNION :";
    printUnion(arr1,arr2);
    cout<<"Intersection :";
    printIntersection(arr1,arr2);

    
}
// UNION :4 2 7 3 9 6 
// Intersection :3 9 