#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void stockSpanProblem(vector<int> stock,vector<int> span){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=0;i<stock.size();i++){
        int currprice=stock[i];
        while(!s.empty() && currprice>=stock[s.top()]){//greater than or equal to current price means we can pop the top element as it is not greater than current price
            s.pop();//we will pop the top element until we find an element which is greater than current price or stack becomes empty
        }
        if(s.empty()){
            span[i]=i+1;
        }else{
            int prevHigh=s.top();//we will get the index of previous high price from stack top and calculate the span by subtracting the index of previous high price from current index
            span[i]=i-prevHigh;//we will get the span by subtracting the index of previous high price from current index
        }
        s.push(i);//we will push the current index into stack as it may be the previous high price for future elements
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;

}

int main(){
    vector<int> stock={100,80,60,70,60,85,100};
    vector<int> span={0,0,0,0,0,0,0};
    stockSpanProblem(stock,span);//1 1 1 2 1 5 7 

    return 0;
}