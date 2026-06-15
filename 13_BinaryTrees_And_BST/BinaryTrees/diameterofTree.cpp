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

void levelorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* curr=Q.front();
        Q.pop();
        if(curr==NULL){// these is for printing the nodes one level in one line
            cout<<endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);//to track next line
        }
     else{
         cout<< curr->data<<" ";
        if(curr->left!=NULL){
            Q.push(curr->left);
        }
        if(curr->right!=NULL){
            Q.push(curr->right);
        }
     }

    }
    cout<<endl;


}

int currHt=0;
//heght of tree
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt=height(root->left);
    int rightHt=height(root->right);

    int currHt=max(leftHt,rightHt)+1;

    return currHt;
}


//diameter of tree
int diam1(Node* root){//O(n^2)
    if(root==NULL){
        return 0;
    }

    int currdiam=height(root->left)+height(root->right)+1;//O(n)
    int leftdia=diam1(root->left);
    int rightdia=diam1(root->right);

    return max(currdiam,max(leftdia,rightdia));
}

pair<int,int> diam2(Node* root){//O(n)*O(1)
    if(root==NULL){
        return make_pair(0,0);
    }
 //(diameter,height)
  pair<int,int> leftInfo=diam2(root->left);
  pair<int,int> rightInfo=diam2(root->right);

  int currDiam=leftInfo.second+rightInfo.second+1;
  int  finalDiam=max(currDiam,max(leftInfo.first,rightInfo.first));
  int finalHt=max(leftInfo.second,rightInfo.second)+1;

  return make_pair(finalDiam,finalHt);
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
     Node *root=buildTree(nodes);
    //  levelorderTraversal(root);
    //  cout<<"height of tree:"<<height(root)<<endl;
    // cout<<"max diameter:"<<diam1(root)<<endl;
 cout<<"max diameter:"<<diam2(root).first<<endl;
 cout<<"height of tree:"<<diam2(root).second<<endl;

    return 0;


}