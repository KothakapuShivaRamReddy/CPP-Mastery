#include<iostream>
using namespace std;

int main(){
    int n;
    int fact=1;
    cout<<"Enter the factorial number:";
    cin>>n;
    for(int i=n;i>=1;i--){
        fact*=i;
        
    }
    cout<<fact<<endl;

    return 0;
}