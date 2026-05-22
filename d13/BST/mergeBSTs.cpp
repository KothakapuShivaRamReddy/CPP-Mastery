
//from BST to BalancedBST using inorder
#include<iostream>
#include<vector>
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



void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void getInorder(Node* root,vector<int> &nodes){
    if(root==NULL){
        return;
    }

    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right,nodes);
}
Node* BSTfromSortedvec(vector<int> nodes, int st,int  end){
    if(st>end){
        return NULL;
    }
      int mid=st+(end-st)/2;
    Node* curr=new Node(nodes[mid]);
      curr->left=BSTfromSortedvec(nodes,st,mid-1);
      curr->right=BSTfromSortedvec(nodes,mid+1,end);

    return curr;
}

// Node* balancedBST2(Node* root){
//     vector<int> nodes;
//     getInorder(root,nodes);

//     return BSTfromSortedvec(nodes,0,nodes.size()-1);

// }
 
Node* mergeBSTs(Node* root1,Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1,nodes1);
    getInorder(root2,nodes2);
   
    int i=0,j=0;
    while(i<nodes1.size() && j<nodes2.size()){
           if(nodes1[i]<nodes2[j]){
              merged.push_back(nodes1[i++]);
           }else{
              merged.push_back(nodes2[j++]);
           }
    }
    while(i<nodes1.size()){
         merged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
         merged.push_back(nodes2[j++]);
    }
    return BSTfromSortedvec(merged,0,merged.size()-1);

}

int main(){
    

    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);
    
    Node* root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);

    Node* mergeRoot=mergeBSTs(root1,root2);
    preorder(mergeRoot);//3 1 2 9 4 12
   

    return 0;

}