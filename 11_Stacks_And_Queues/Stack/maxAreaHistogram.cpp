#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int maxAreaHistogram(vector<int> height){
    int n=height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;
    
    //nsl 
    nsl[0]=-1;
    s.push(0);
    
    for(int i=0;i<height.size();i++){
        int curr=height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);
    }
    printVector(nsl);
    while(!s.empty()){
        s.pop();
    }

    //nsr
   
    s.push(n-1);
    nsr[n-1]=n;
    for(int i=n-2;i>=0;i--){
        int curr=height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;

        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }
    printVector(nsr);
    int maxArea=0;
    for(int i=0;i<n;i++){
        int ht=height[i];
        int width=nsr[i]-nsl[i]-1;
        int area=ht*width;

        maxArea=max(area,maxArea);
    }
    cout<<"the max area of histogram:"<<maxArea;
}


int main(){

    vector<int> height={2,1,5,6,2,3};
    maxAreaHistogram(height);//the max area of histogram:10
    return 0;  

}
//-1 -1 1 2 1 4 
// 1 6 4 4 6 6 
// the max area of histogram:10
