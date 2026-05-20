#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> m;

    m[101]="shiva";
    m[102]="ram";
    m[110]="reddy";
    m[103]="ramesh";

    cout<<m[101]<<endl;
    m[103]="suresh";
    cout<<m[103]<<endl;
    cout<<m.count(104)<<endl;
    cout<<m.count(101)<<endl;
    for(auto it:m){
      cout<<"key :"<<it.first<<","<<"value:"<<it.second<<endl;
    }


    return 0;
}

// shiva
// suresh
// 0
// 1
// key :101,value:shiva
// key :102,value:ram
// key :103,value:suresh
// key :110,value:reddy