#include<iostream>
#include<set>
using namespace std;


int main(){
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    // s.insert(1);
    // s.insert(1);
    cout<<s.size()<<endl;

    cout<<(s.find(1)!=s.end())<<endl;
    
    for(int x:s){
        cout<<x<<endl;
    }
  
}