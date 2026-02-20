#include<iostream>
using namespace std;

void Countbits(int num){
    int count=0;
    while(num>0){
       int lastdigit=num & 1;
       count+=lastdigit;
       num=num>>1;
    }
    cout<<count;
}

int main(){
    Countbits(3);
    return 0;
}
//counting number of 1 bits in a number