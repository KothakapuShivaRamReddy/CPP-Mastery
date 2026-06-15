

#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int>* l;
    public:
      Graph(int v){
        this->V=v;
        l=new list<int> [V];
      }
  

    void addEdge(int u,int v){//by default we are assuming that the graph is undirected
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbours=l[u];
            cout<<u<<":";
            for(int v:neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

   bool undirCycleHelper(int src, int par,vector<bool> &vis){
        vis[src]=true;
        for(int v:l[src]){
            if(!vis[v]){
                
                if(undirCycleHelper(v,src,vis)){
                    return true;
                }}
                else{
                    if(v!=par){//cycle found
                        return true;
                    }
                }
            }
            return false;
        }
        
   
   bool undirCycle(){
    vector<bool> vis(V,false);
    return undirCycleHelper(0,-1,vis);
   }

};

int main(){
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2); 
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);
    
   cout<<graph.undirCycle()<<endl;

    return 0;
}
