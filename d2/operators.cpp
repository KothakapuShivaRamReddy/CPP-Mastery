#include<iostream>
using namespace std;

int main(){
    int a=3;
    int b;
    b=a++;
    cout<<b<<endl;
    a=3;
    b=++a;
    
    cout<<b<<endl;

    int x=10,y=5;
    cout<<(x%5)<<endl;
    int exp1=(y*(x/y+x/y));
    int exp2=(y*x/y+y*x/y);
    cout<<exp1<<"";
    cout<<exp2<<"\n";
return 0;}