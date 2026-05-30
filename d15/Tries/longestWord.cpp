// Given a list of strings, find the longest string in the list such that every prefix of the string is also present in the list.
// For example, if the input list is ["a", "banana", "app", "appl", "ap", "apply", "apple"], the output should be "apple" because:
// - "a" is a prefix of "apple" and is present in the list.
// - "ap" is a prefix of "apple" and is present in the list.
// - "app" is a prefix of "apple" and is present in the list.
// - "appl" is a prefix of "apple" and is present in the list.
// - "apple" is present in the list.
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Node{
    public:

    unordered_map<char,Node*> children;
    bool endofword;
    Node(){
        endofword=false;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string key){ //O(L) : L length of string
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
           temp=temp->children[key[i]];

        }
        temp->endofword=true;
    }
    bool search(string key){ //O(L) : L length of string
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endofword;
    }


    void longestStringHelper(Node* root,string &ans,string temp){
        cout<<"recursion - temp: "<<temp<<endl;
        for(pair<char,Node*> m:root->children){//iterating through the children of the current node
            cout<<"m.first: "<<m.first<<" m.second->endofword: "<<m.second->endofword<<endl;
            if(m.second->endofword){
                temp+=m.first;
                if((temp.size()==ans.size() && temp<ans) || temp.size()>ans.size()){//if the size of temp string is greater than ans string or if the size is same but temp string is lexicographically smaller than ans string then we update our answer
                    ans=temp;
                    cout<<"ans: "<<ans<<endl;
                }
                longestStringHelper(m.second,ans,temp);
                 cout<<"temp: "<<temp<<endl;
    
                temp=temp.substr(0,temp.size()-1);//backtracking // we are removing the last character from temp string to explore other branches of the trie
                 cout<<"backtracking - temp: "<<temp<<endl;
            }
        }
    }
    string longestString(){
        string ans="";
        longestStringHelper(root,ans,"");
        return ans;
    }
};

string longestWord(vector<string> &dict){
    Trie trie;

    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    return trie.longestString();
}

int main(){
    vector<string> dict={"a","banana","app","appl","ap","apply","apple"};
    cout<<longestWord(dict)<<endl;

    return 0;
}