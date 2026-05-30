

#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int>* l;
    bool undir;
    public:
      Graph(int v,bool undir=true){
        this->V=v;
        l=new list<int> [V];
        this->undir=undir;
      }
  

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(undir){
               l[v].push_back(u);
        }
       
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
   bool dirCycleHelper(int src,vector<bool> &vis,vector<bool> &recpath){//O(V+E)
       vis[src]=true;
       recpath[src]=true;

       for(int v:l[src]){
           if(!vis[v]){
              if(dirCycleHelper(v,vis,recpath)){//cycle found in the subtree of v 
                return true;
              }
           }else{
             if(recpath[v]){//cycle found
                return true;
             }
           }
       }
       recpath[src]=false;//backtracking step
       return false;

   }

   bool dirCycle(){//O(V+E)
    vector<bool> vis(V,false);
    vector<bool> recpath(V,false);
    for(int i=0;i<V;i++){//to handle disconnected components because cycle can be present in any of the components it was directed graph so we cannot assume that cycle will be present in the component which has 0 as a vertex
        if(!vis[i]){
            if(dirCycleHelper(i,vis,recpath)){//
                return true;
            }
        }
    }
    return false;//cycle not found in any of the components
   }
};

int main(){
    Graph graph(4,false);

    graph.addEdge(1,0);
    graph.addEdge(0,2); 
    // graph.addEdge(2,0); 
    graph.addEdge(2,3);
   
    graph.addEdge(3,0);
    
   cout<<graph.dirCycle()<<endl;

    return 0;
}
