//paytm
//Print all Binary Strings of size N without any consecutive 1s.

#include<iostream>
using namespace std;

// void binary(int n,int lastplace,string ans){

//     if(n==0){
//         cout<<ans<<endl;
//         return;
//     }
//     if(lastplace!=1){
//         binary(n-1,0,ans+'0');
//          binary(n-1,1,ans+'1');
//     }else{
//         binary(n-1,0,ans+'0');
//     }
// }

void binary(int n,string ans){

    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.size()-1]!='1'){//taking char here as condition because in main it had empty ans=" " to statisfy that ans
        binary(n-1,ans+'0');
         binary(n-1,ans+'1');
    }else{
        binary(n-1,ans+'0');
    }
}

int main(){
    int lastprice=0;
    string ans=" ";
    binary(3,ans);
    return 0;
}