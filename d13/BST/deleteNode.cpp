#include<iostream>
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

Node* insert(Node* root,int val){
     
    if(root==NULL){
       root=new Node(val);
       return root;
    }

    if(val<root->data){//left subtree
        root->left=insert(root->left,val);
    }else{//right subtree
        root->right=insert(root->right,val);
    }

  return root;
}

Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    
}


Node* getInorderSuccessor(Node* root){//not defining null because the called root comes under case 3 which had two childrens
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* delNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left=delNode(root->left,val);
    }else if(val>root->data){
        root->right=delNode(root->right,val);
    }else{
        //root==val
        //case1:0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //case2: 1 children
        if( root->left==NULL || root->right==NULL){
            return root->left==NULL?root->right:root->left;
        }
       //case3:2 childrens
      
       //inorder successor
       Node* IS= getInorderSuccessor(root->right);
       root->data=IS->data;
       root->right=delNode(root->right,IS->data);
       return root;
    }
}
int main(){
    //  int arr[6]={5,1,3,4,2,7};
     int arr2[9]={8,5,3,1,4,6,10,11,14};

     Node* root=buildBST(arr2,9);
    
     inorder(root);
     cout<<endl;
     delNode(root,4);
     inorder(root);
     cout<<endl;


    return 0;
}
// 1 3 4 5 6 8 10 11 14 
// 1 3 5 6 8 10 11 14 