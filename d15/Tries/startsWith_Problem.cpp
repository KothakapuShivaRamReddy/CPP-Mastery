// Given a dictionary of words and a prefix, find if there is any word in the dictionary that starts with the given prefix.
// For example, if the dictionary is ["apple", "app", "mango", "man", "women"]
// and the prefix is "app", the output should be true because both "apple" and "app" start with "app".

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
    public:
    Node* root;
    
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
};


bool startswith(vector<string> &dict,string key){
    Trie trie;

    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    Node* temp=trie.root;
    for(int i=0;i<key.size();i++){
        if(temp->children.count(key[i])==0){
            return false;
        }
        temp=temp->children[key[i]];
    }
    return true;
}


int main(){
    vector<string> words={"apple","app","mango","man","women"};
    string pre="app";

    cout<<startswith(words,pre);

    return 0;
}