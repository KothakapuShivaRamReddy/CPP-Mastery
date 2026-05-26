#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    m["China"]=150;
    m["India"]=150;
    m["US"]=50;
    m["UK"]=30;
    cout<<m["India"]<<endl;
    m["UK"]=20;
    cout<<m["UK"]<<endl;

    for(pair<string,int> p:m){
        cout<<"key :"<<p.first<<","<<"value:"<<p.second<<endl;
    }
  
    cout<<m.count("Nepal")<<endl;
m.erase("UK");
    for(pair<string,int> p:m){  
        cout<<"key :"<<p.first<<","<<"value:"<<p.second<<endl;
    }
  
}

// 150
// 20
// key :UK,value:20
// key :US,value:50
// key :India,value:150
// key :China,value:150

// 0
// key :US,value:50
// key :India,value:150
// key :China,value:150