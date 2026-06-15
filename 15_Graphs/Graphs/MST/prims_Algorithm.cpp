

#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>* l;
    bool undir;
    public:
      Graph(int v,bool undir=true){
        this->V=v;
        l=new list<pair<int,int>> [V];
        this->undir=undir;
      }
  

    void addEdge(int u,int v,int wt){
        l[u].push_back(make_pair(v,wt));
        if(undir){
               l[v].push_back(make_pair(u,wt));
        }
       
    }
    // void print(){
    //     for(int u=0;u<V;u++){
    //         list<int> neighbours=l[u];
    //         cout<<u<<":";
    //         for(int v:neighbours){
    //             cout<<v<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    void prims(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //(wt,v)->minHeap

        vector<bool> Mst(V,false);
        pq.push(make_pair(0,src));
        int ans=0;

        while(pq.size()>0){
            int u=pq.top().second;
            int cost=pq.top().first;
            pq.pop();
            if(!Mst[u]){
                Mst[u]=true;
                ans+=cost;
                list<pair<int,int>> neighbours=l[u];
                for(pair<int,int> n:neighbours){
                    int v=n.first;
                    int currWt=n.second;
                    pq.push(make_pair(currWt,v));
                }
            }

        }

        cout<<"Final cost of MST:"<<ans<<endl;
    }
   
  
};

int main(){
    Graph graph (4);
graph.addEdge(0, 1, 10);
graph.addEdge(0, 2, 15);
graph.addEdge(0, 3, 30);
graph.addEdge(1, 3, 40);
graph.addEdge(2, 3, 50);

   
graph.prims(0);

    return 0;
}
