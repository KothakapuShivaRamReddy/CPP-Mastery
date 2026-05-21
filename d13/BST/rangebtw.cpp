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



void range(Node* root,int start,int end){
    if(root==NULL){
        return;
    }
   //case 1
    if(start<=root->data && root->data<=end){//in range print and go to both sides
        cout<<root->data<<" ";
        range(root->left,start,end);
        range(root->right,start,end);
    }

    else if(root->data<start){//case 2
        range(root->right,start,end);//go to right because left will be smaller than root and root is already smaller than start
    }
    else{//case 3 root->data>end
        range(root->left,start,end);//go to left because right will be greater than root and root is already greater than end
    }
}

int main(){
    //  int arr[6]={5,1,3,4,2,7};
     int arr2[9]={8,5,3,1,4,6,10,11,14};

     Node* root=buildBST(arr2,9);
    
    range(root,5,12);


    return 0;
}
//8 5 6 10 11