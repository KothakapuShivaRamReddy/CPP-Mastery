#include<iostream>
#include<vector>
#include<climits>
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
        tree[node]=min(tree[2*node+1],tree[2*node+2]);
    }

    int rangeMin(int qi,int qj,int si,int sj,int node){
        
        if(qi>sj || qj<si){//no overlap
            return INT_MAX;
        }
        if(qi<=si && qj>=sj){ //complete overlap
            return tree[node];
        }

        //partial overlap
        int mid=si+(sj-si)/2;
        int leftSum=rangeMin(qi,qj,si,mid,2*node+1);
        int rightSum=rangeMin(qi,qj,mid+1,sj,2*node+2);
        return min(leftSum,rightSum)    ;
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
        tree[node]=min(tree[2*node+1],tree[2*node+2]);
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

    int MinQuery(int qi,int qj){
        return rangeMin(qi,qj,0,n-1,0);
    }
    int updateQuery(int idx,int newVal){
        updateUtil(idx,newVal,0,n-1,0);
    }
};



int main(){
    vector<int> arr={6,8,-1,2,17,1,3,2,4};
    SegmentTree st(arr);
    st.printSegTree();//-1 -1 1 2 17 1 3 2 4 6 8 -1 2 17 1 3 2 4
    cout<<st.MinQuery(2,5)<<endl;//-1

    st.updateQuery(4,5);//17->5
    cout<<st.MinQuery(0,8)<<endl;//-1

    
    return 0;
}