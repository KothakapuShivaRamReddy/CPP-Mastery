// Given a string, count the number of unique substrings in it. 
// For example, if the input string is "ababa",
// the output should be 10 because the unique substrings are "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", and "ababa"including the empty string.

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

    int countHelper(Node* root){
       Node* temp=root;
        int ans=0;
        for(auto m:temp->children){
            ans+=countHelper(m.second);
        }
        return ans+1;
    }
    int countNodes(){
   return countHelper(root);
    }
};

int countUniqueSubstr(string s){
    Trie trie;
   // suffix trie building
    for(int i=0;i<s.size();i++){
        string suffix=s.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main(){
    string s="ababa";

    cout<<countUniqueSubstr(s);
    return 0;
}