
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

    void helper(int src,int dest,vector<bool> &vis,string path){
        if(src==dest){
            cout<<path<<dest<<endl;
            return;
        }

        vis[src]=true;
        path+=to_string(src);
        for(int v:l[src]){
            if(!vis[v]){  
               
                helper(v,dest,vis,path);
            }
        }

        path=path.substr(0,path.size()-1);//backtracking
        vis[src]=false;//backtracking for getting other paths if any vis is true then it will not be considered for other paths and we will miss some paths 
    }

  void printAllPaths(int src,int dest){
    vector<bool> vis(V,false);
    string path=" ";
    helper(src,dest,vis,path);
  }
};

int main(){
   
Graph graph (6, false);
graph.addEdge(0, 3);
graph.addEdge(2, 3);
graph.addEdge(3, 1);
graph.addEdge(4, 0);
graph.addEdge(4, 1);
graph.addEdge(5, 0);
graph.addEdge(5, 2);
    graph.printAllPaths(5,1);

    return 0;
}
