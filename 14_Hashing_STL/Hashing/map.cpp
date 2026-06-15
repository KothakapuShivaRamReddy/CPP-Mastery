#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int> m;

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
//  the order is based on the key which is string in this case, so the output will be in sorted order of the keys
    return 0;
}

// 150
// 20
// key :China,value:150
// key :India,value:150
// key :UK,value:20
// key :US,value:50
// 0
// key :China,value:150
// key :India,value:150
// key :US,value:50