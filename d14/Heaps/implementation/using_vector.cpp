#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;
 public:
    void push(int val){//O(logn)
        //step-1 insert
       vec.push_back(val);
       //step-2
       int x=vec.size()-1;//child
       int parI=(x-1)/2;//parent
       while(parI>=0 && vec[x]>vec[parI]){//if we want min heap then vec[x]< vec[parI]
           swap(vec[x],vec[parI]);
           x=parI;
           parI=(x-1)/2;
       }
    }

    void Heapify(int i){

        if(i>=vec.size()){
            return;
        }
        int l=2*i+1;
        int r=2*i+2;

        int maxI=i;
        if(l<vec.size()  && vec[l]>vec[maxI]){//if we want min heap then vec[l]<vec[maxI]
            maxI=l;
        }
        if(r<vec.size() && vec[r]>vec[maxI]){// if we want min heap then vec[r]<vec[maxI]
            maxI=r;
        }

        swap(vec[i],vec[maxI]);//swap with the largest element among parent and children
        if(maxI!=i){// if we are swapping then only we need to heapify the child
            Heapify(maxI);
        }

    }

    void pop(){
        //step 1
        swap(vec[0],vec[vec.size()-1]);

        //step2
        vec.pop_back();
        //step3
        Heapify(0);

    }
    int top(){
       return vec[0];
    }

    bool empty(){
        return vec.size()==0;
    }
};

int main(){
   Heap heap;
   heap.push(9);
   heap.push(4);
   heap.push(8);
   heap.push(1);
   heap.push(2);
   heap.push(5);
  while(!heap.empty()){
      cout<<"top:"<<heap.top()<<endl;
      heap.pop();
    }
    return 0;
}
// top:9
// top:8
// top:5
// top:4
// top:2
// top:1