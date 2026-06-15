#include<iostream>
#include<vector>
using namespace std;

class SegmentTree{
    vector<int> tree;
    int n;
    void buildTree(vector<int> &arr,int start,int end,int node){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        buildTree(arr,start,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int rangeSum(int qi,int qj,int si,int sj,int node){
        
        if(qi>sj || qj<si){//no overlap
            return 0;
        }
        if(qi<=si && qj>=sj){ //complete overlap
            return tree[node];
        }

        //partial overlap
        int mid=si+(sj-si)/2;
        int leftSum=rangeSum(qi,qj,si,mid,2*node+1);
        int rightSum=rangeSum(qi,qj,mid+1,sj,2*node+2);
        return leftSum+rightSum;
    }

    void updateUtil(int idx,int newVal,int start,int end,int node){
        if(start==end){
            tree[node]=newVal;
            return;
        }
        int mid=start+(end-start)/2;
        if(idx>=start && idx<=mid){
            updateUtil(idx,newVal,start,mid,2*node+1);
        }
        else{
            updateUtil(idx,newVal,mid+1,end,2*node+2);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
public:
    SegmentTree(vector<int> &arr){
        n=arr.size();
        tree.resize(4*n,0);
        buildTree(arr,0,n-1,0); 
    }


    void printSegTree(){
        for(int el:tree){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    int rangeQuery(int qi,int qj){
        return rangeSum(qi,qj,0,n-1,0);
    }

    void updateQuery(int idx,int newVal){
        // int diff=newVal-tree[0]; //difference between new value and old value at the root
        updateUtil(idx,newVal,0,n-1,0);
    }
};



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    SegmentTree st(arr);
    st.printSegTree();
    cout<<st.rangeQuery(2,5)<<endl;//3+4+5+6=18
    cout<<st.rangeQuery(0,3)<<endl;//1+2+3+4=10
    cout<<st.rangeQuery(6,7)<<endl;//7+8=15

    st.updateQuery(1,3); //update index 1 to value 3
    cout<<st.rangeQuery(0,3)<<endl;//1+3+3+4=11
    return 0;
}