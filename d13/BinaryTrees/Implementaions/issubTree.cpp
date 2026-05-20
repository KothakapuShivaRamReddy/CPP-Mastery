#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
static int idx=-1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node *currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);

    return currNode;
}


bool isidentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }else if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data!=root2->data){
        return false;
    }
    return isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right);
}

bool issubTree(Node* root,Node* subRoot){
    if(root==NULL && subRoot==NULL){
        return true;
    }else if(root==NULL || subRoot==NULL){
        return false;
    }


    if(root->data==subRoot->data){
        if(isidentical(root,subRoot)){
            return true;
        }
    }

    bool leftsubtree=issubTree(root->left,subRoot);
    if(!leftsubtree){
        return issubTree(root->right,subRoot);
    }
    return true;
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
     Node *root=buildTree(nodes);
    
     Node* subRoot=new Node(2);
     subRoot->left=new Node(4);
     subRoot->right=new Node(5);

     cout<<issubTree(root,subRoot)<<endl;
    return 0;


}