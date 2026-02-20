#include<iostream>
using namespace std;
 
void bintodec(int binnum){
    int n= binnum;
    int pow=1;
    int decimal=0;
    int lastnum=0;
    while(n>0){
        lastnum=n%10;
         decimal+=lastnum*pow;
         pow=pow*2;
         n=n/10;
    }
    cout<<"decimal:"<<decimal;
}

void dectobin(int decnum){
    int n=decnum;
    int binary=0;
    int pow=1;
    int rem=0;
    while(n>0){
        rem=n%2;
        binary+=rem*pow;
        pow=pow*10;
        n=n/2;

    }
    cout<<endl;
    cout<<"Binary:"<<binary;
}


int main(){
    bintodec(101);
    dectobin(32);

    return 0;

}
// decimal:5
// Binary:100000