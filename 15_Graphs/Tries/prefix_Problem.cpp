// Given a list of words, find the shortest unique prefix to represent each word in the list.
// For example, if the input is ["zebra", "dog", "duck", "dove"], the output should be ["z", "dog", "du", "dov"] because:
// - "z" is the shortest unique prefix for "zebra"
// - "dog" is the shortest unique prefix for "dog"
// - "du" is the shortest unique prefix for "duck"
// - "dov" is the shortest unique prefix for "dove"

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Node{
    public:

    unordered_map<char,Node*> children;
    bool endofword;
    int freq;
    Node(){
        endofword=false;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
        root->freq=-1;
    }

    void insert(string key){ //O(L) : L length of string
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
                temp->children[key[i]]->freq=1;
            }else{
                temp->children[key[i]]->freq++;
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
    string getPrefix(string s){
    Node* temp=root;
    string prefix="";
    for(int i=0;i<s.size();i++){
        prefix+=s[i];
        if(temp->children[s[i]]->freq==1){
            break;
        }
        temp=temp->children[s[i]];
    }
    return prefix;
}
};



void prefixProblem(vector<string> &dict){//O(N*L) : N number of words, L length of longest word
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    for(int i=0;i<dict.size();i++){
        cout<<trie.getPrefix(dict[i])<<endl;
    }
}

int main(){
    vector<string> dict={"zebra","dog","duck","dove"};

   
   prefixProblem(dict);


    return 0;
}

//z
// dog
// du
// dov