#include<iostream>
#include<vector>
#include<stack> 
using namespace std;
bool validParenthesis(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='(' || ch=='{'||ch=='['){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return false;
            }
            char top=s.top();
            if((top=='(' && ch==')')|| (top=='{' && ch=='}')|| top=='[' && ch==']'){
                s.pop();
            }
        }
    }
    return s.empty();
}
int main(){
    string str1="({])}";
    string str2="({[]})";

    cout<<validParenthesis(str1)<<endl;
    cout<<validParenthesis(str2)<<endl;
}

