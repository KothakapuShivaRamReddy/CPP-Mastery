#include<iostream>
#include<stack>
#include<string>
using namespace std;
using namespace std;

string reverseString(string s){
    string ans;
    stack<char> st;

    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    while(!st.empty()){//empty is fnx
          char temp=st.top();
          ans+=temp;
          st.pop();

    }
    return ans;

}

int main(){
    string s="abcd";


    cout<<reverseString(s);//dcba

}