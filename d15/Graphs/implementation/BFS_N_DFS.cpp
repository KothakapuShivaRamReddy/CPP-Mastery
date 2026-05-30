//unweighted graph implementation using adjacent list

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
    void bfs(){  //O(V+E)
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0]=true;

        while(q.size()>0){
            int u=q.front();
            q.pop();

            cout<<u<<" ";
            list<int> neighbours=l[u];
            for(int v:neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }

        }
        cout<<endl;
    }
    void dfsHelper(int u,vector<bool> &vis){//O(V+E)
        vis[u]=true;
        cout<<u<<" ";

        list<int> neighbours=l[u];
        for(int v:neighbours){
            if(!vis[v]){
        
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(7,false);
        dfsHelper(0,vis);
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
    graph.addEdge(5,6);


    graph.bfs();

    graph.dfs();


    return 0;
}

// 0 1 2 3 4 5 6 
// 0 1 3 4 2 5 6 