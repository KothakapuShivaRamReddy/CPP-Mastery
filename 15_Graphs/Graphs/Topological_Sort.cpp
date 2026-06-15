

#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>
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

    void topoHelper(int src,vector<bool> &vis,stack<int> &s ){
        vis[src]=true;
        //  list<int> neighbours=l[src];
        for(int v:l[src]){
            if(!vis[v]){
                topoHelper(v,vis,s);
            }
        }

        s.push(src);

    }
    void topoSort(){

        vector<bool> vis(V,false);
        stack<int> s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoHelper(i,vis,s);
        }
    }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }

    }
  
};

int main(){
    Graph graph(6,false);

    graph.addEdge(2,3);
    graph.addEdge(3,1); 
     
    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort();
    //542310


    return 0;
}
