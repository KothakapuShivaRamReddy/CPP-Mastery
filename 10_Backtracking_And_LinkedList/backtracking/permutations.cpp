#include<iostream>
using namespace std;

void permutations(string s,string subset){
     int n=s.size();
    if(n==0){
        cout<<subset<<"\n";
        return;
    }
   

    for(int i=0;i<n;i++){
        char ch=s[i];
        string nextstr=s.substr(0,i)+s.substr(i+1,n-i-1);
        permutations(nextstr,subset+ch);

    }
}

int main(){

    string str="abc";
    string subset="";

    permutations(str,subset);
    
    return 0;

}