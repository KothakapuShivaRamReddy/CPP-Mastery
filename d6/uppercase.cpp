#include<iostream>
#include<cstring>
using namespace std;
void uppercase(char word[],int n){
    for(int i=0;i<n;i++){
       char ch=word[i];
       if(ch>='a'&& ch<='z'){
        int a=ch-'a'+'A';
        ch=a;
       }
       word[i]=ch;
    }
    cout<<word;
}


int main(){

    char word[]="aPple";
    uppercase(word,strlen(word));

    return 0;
}