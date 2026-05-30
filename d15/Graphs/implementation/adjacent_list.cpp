//unweighted graph implementation using adjacent list

#include<iostream>
#include<list>
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
};

int main(){
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2); 
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    graph.print();


    return 0;
}

// 0:1
// 1:0 2 3  
// 2:1 3 4
// 3:1 2
// 4:2