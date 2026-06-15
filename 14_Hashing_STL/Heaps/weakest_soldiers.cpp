/*
this code is to find the K weakest soldiers in a matrix where each row represents a group of soldiers and the value 1 
 represents a soldier and 0 represents an empty space. The soldiers are arranged in such a way that all the soldiers are on the left 
 side of the row and all the empty spaces are on the right side of the row. The weakness of a row is determined by the number of soldiers in that row. 
 If two rows have the same number of soldiers, then the row with the smaller index is considered weaker.
*/  
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Row{
    public:
    int idx;
    int count;

    Row(int idx,int count){
        this->idx=idx;
        this->count=count;
    }

    bool operator <(const Row &obj) const{
       if (this->count==obj.count) {
        return this->idx>obj.idx;//if count is same then we want the smaller index to come first
       }
       
        return this->count>obj.count;//minheap
    }
};

void weakestSoldiers(vector<vector<int>> &matrix,int k){
    vector<Row> rows;
    for(int i=0;i<matrix.size();i++){
        int count=0;
        for(int j=0;j<matrix[i].size() && matrix[i][j]==1;j++){
            count++;
        }
        rows.push_back(Row(i,count));
    }

    priority_queue<Row> pq(rows.begin(),rows.end());

    for(int i=0;i<k;i++){
        cout<<"row:"<<pq.top().idx<<endl;//0 2
        pq.pop();
    }
}
int main(){
   vector<vector<int>> matrix={{1,0,0,0},
                              {1,1,1,1},
                               {1,0,0,0},
                               {1,0,0,0}};

    weakestSoldiers(matrix,2);
}