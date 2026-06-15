#include<iostream>
using namespace std;

int product(int a,int b){
    return a*b;
}

int main(){
   int a,b;
   cout<<"Enter the values of a & b :";
   cin>>a>>b;

   int p=product(a,b);
   cout<<"sum is:"<<p;
   

    return 0;

}