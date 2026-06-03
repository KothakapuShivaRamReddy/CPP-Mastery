#include<iostream>
#include<queue>
#include<climits>

using namespace std;

class Edge{

public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }

};


void bellmanFord(int src,vector<vector<Edge>> &graph,int V){//O(V*E)
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    for(int i=0;i<V-1;i++){//V
        for(int u=0;u<V;u++){//E
            for(Edge e:graph[u]){
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v]=dist[u]+e.wt; 
                }
            }
        }
    }
   for(int d:dist){
    cout<<d<<" ";
   }
}

int main(){
    vector<vector<Edge>> graph(5);

  graph[0].push_back(Edge (1, 2));
  graph[0].push_back(Edge(2, 4));
  graph[1].push_back(Edge(2, -4));
  graph[2].push_back(Edge(3, 2));
  graph[3].push_back(Edge(4, 4));
  graph[4].push_back(Edge (1, -1));

   bellmanFord(0,graph,5);//0 2 -2 0 4

   return 0;

}

