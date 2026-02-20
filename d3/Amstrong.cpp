#include<iostream>
using namespace std;
int main(){

    int n=153;
    int num=n;//we took num because if we use in the loop as n it will reduced to 0 as like the num in while that why we used the num=n
    int checksum=0;
    int rem;

    while(num>0){
        rem=num%10;
        checksum+=rem*rem*rem;
        num=num/10;
    }
   if(checksum==n){
    cout<<"armstrong";

   }else{
    cout<<"not";
   }
    // cout<<(checksum==n)?"armstrong":"not";

    return 0;

}