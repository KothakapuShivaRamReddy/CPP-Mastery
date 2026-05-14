#include<iostream>
#include<vector>
#include<stack>
using namespace std;


bool validParenthesis(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch!=')'){
            s.push(ch);
        }

        
        else{
          if(s.top()=='('){
             return true;
          }
          else{
              while(s.top()!='('){
                  s.pop();
              }
              s.pop();
          }
    }
}  return false;
}
int main(){
    string str1="((a+b))";//1
    string str2="(a+b)";//0


    cout<<validParenthesis(str1)<<endl;
    cout<<validParenthesis(str2)<<endl;
}