#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>* l;
    public:
    Graph(int v){
        this->V=v;
        l=new list<pair<int,int>> [V];
    }
    // void addEdge(int u,int v,int weight,bool undir=true){
    //     l[u].push_back({v,weight});
    //     if(undir){
    //         l[v].push_back({u,weight});
    //     }
    // }
    void addEdge(int u,int v,int weight){//by default we are assuming that the graph is undirected
        l[u].push_back({v,weight});
        l[v].push_back({u,weight});
    }
    void print(){
        for(int u=0;u<V;u++){
            list<pair<int,int>> neighbours=l[u];
            cout<<u<<":";
            for(pair<int,int> v:neighbours){
                cout<<"("<<v.first<<","<<v.second<<") ";
            }
            cout<<endl;
        }
    }

};


int main(){
    Graph graph(5);

    graph.addEdge(0,1,10);
    graph.addEdge(1,2,20); 
    graph.addEdge(1,3,30);
    graph.addEdge(2,3,40);
    graph.addEdge(2,4,50);

    graph.print();
    return 0;
}

// 0:(1,10)
// 1:(0,10) (2,20) (3,30)
// 2:(1,20) (3,40) (4,50)
// 3:(1,30) (2,40)
// 4:(2,50)
+