#include<iostream>
using namespace std;
int main(){
    //implict typeconversion
    cout<<(10/3)<<endl;
    cout<<(10/3.0)<<endl;
    cout<<('A'+1)<<endl;

    // explicit
    cout<<(bool)3+2<<endl;
    cout<<(23.5+2+'A')<<endl;
    cout<<(char)('A'+1)<<endl;
}