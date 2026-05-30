
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

    bool bipartite(){
        // vector<bool> vis(V,false);
        vector<int> color(V,-1);
        queue<int> q;
        q.push(0);
        color[0]=0;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(int v:l[curr]){
                // if(!vis[v]){
                if(color[v]==-1){//unvisited
                    // vis[v]=true;
                    color[v]= !color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
};

int main(){
    Graph graph(4);

    graph.addEdge(0,1);
    graph.addEdge(0,2); 
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    // graph.addEdge(0,3);

    cout<< graph.bipartite();

    return 0;
}
 