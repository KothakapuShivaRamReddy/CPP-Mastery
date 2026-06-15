//static varable in functions

#include<iostream>
using namespace std;

void example(){
    // int count=0;
    static int count=0;
    count++;
    cout<<"count="<<count<<endl;
}

int main(){
     example();
     example();
     example();
    return 0;
}