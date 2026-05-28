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
};

int main(){
    vector<string> words={"the","a","there","their","any","thee"};
    Trie trie;

    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }

    cout<< trie.search("their")<<endl;//1
     cout<< trie.search("these")<<endl;//0
    return 0;
}