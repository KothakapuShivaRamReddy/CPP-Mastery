#include<iostream>
using namespace std;

void printsubsets(string s,string subset){
    if(s.size()==0){
        cout<<subset<<"\n";
        return;
    }
    char ch=s[0];

    //yes choice
    printsubsets(s.substr(1,s.size()-1),subset+ch);

    //no choice
    printsubsets(s.substr(1,s.size()-1),subset);


}

int main(){
      string str="abc";
      string subset="";
      printsubsets(str,subset);
    

   return 0;
}