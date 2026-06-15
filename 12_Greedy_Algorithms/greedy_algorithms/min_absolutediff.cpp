#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> A={4,1,8,7};
    vector<int> B={2,3,6,5};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int absdiff=0;
    for(int i=0;i<A.size();i++){
        absdiff+=abs(A[i]-B[i]);
    }
    
    cout<<"MIN diff is:"<<absdiff;//6
    return 0;
}