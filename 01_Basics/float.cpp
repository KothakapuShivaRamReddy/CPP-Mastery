#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float a=1.234567890123;
    double b=1.234567890123;

    cout<<setprecision(10)<<"float="<<a<<endl;
    cout<<setprecision(10)<<"double="<<b<<endl;
    return 0;

}
