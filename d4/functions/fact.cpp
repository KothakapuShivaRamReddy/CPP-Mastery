#include<iostream>
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }else{
        return n*fact(n-1);

    }
}
// int fact=1
// for(int i=1;i<=n;i++){
//     fact*=i;
// }

int main(){
    int n;
    cout<<"Fact of no:";
    cin>>n;
    cout<< fact(n);
   
    return 0;

}