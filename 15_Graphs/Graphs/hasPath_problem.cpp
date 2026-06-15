
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
    //   void addEdge(int u,int v,bool undir=true){
    //     l[u].push_back(v);
    //     if(undir){
    //         l[v].push_back(u);
    //     }
    //   }

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

    bool hasPathHelper(int src,int dest,vector<bool> &vis){//O(V+E)
        if(src==dest){
            return true;
        }
        vis[src]=true;
        for(int v:l[src]){
            if(!vis[v]){
                if(hasPathHelper(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src,int dest){
        vector<bool> vis(V,false);
        return hasPathHelper(src,dest,vis);
    }
};

int main(){
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2); 
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    // graph.addEdge(5,6);

   cout<<graph.hasPath(0,6);
   


    return 0;
}

