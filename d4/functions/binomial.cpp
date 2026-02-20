#include<iostream>
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }else{
        return n*fact(n-1);

    }
}

int bio(int n,int r){
    int fact_n=fact(n);
    int fact_nr=fact(n-r);
    int fact_r=fact(r);
    int bino=fact_n/(fact_nr*fact_r);
    return bino;
}

int main(){
    int n,r;
    cout<<"enter n& C:";
    cin>>n>>r;
    cout<<bio(n,r);
    
   
    return 0;

}