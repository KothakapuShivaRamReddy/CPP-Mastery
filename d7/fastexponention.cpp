#include<iostream>
using namespace std;
int exponention(int x,int n){
     int ans=1;
    while(n>0){
        int last=n&1;
        if(last){
           ans=ans*x;
        }
        x=x * x;
        n=n>>1;
       

    } return ans;
}


int main(){
  cout<<exponention(4,2);
 return 0;
}
//x^n code in binary
