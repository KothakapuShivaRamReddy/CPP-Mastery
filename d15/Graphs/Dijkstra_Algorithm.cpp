#include<iostream>
#include<queue>
#include<climits>
// #include<iomanip>
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


void dijkstra(int src,vector<vector<Edge>> &graph,int V){//O((V+E)logV)
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;//(dist[v],v);
    vector<int> dist(V,INT_MAX);

    pq.push(make_pair(0,0));
    dist[0]=0;

    while(pq.size()>0){
        int u=pq.top().second;
       pq.pop();

       vector<Edge> neighbours=graph[u];
       for(Edge e:neighbours){
        if(dist[e.v]>dist[u]+e.wt){
            dist[e.v]=dist[u]+e.wt;
            cout<<dist[e.v]<<"..."<<e.v<<endl;
            pq.push(make_pair(dist[e.v],e.v));
            cout<<"top:"<<pq.top().first<<"-"<<pq.top().second<<endl;;
        }
       }

       
    }

    for(int d:dist){
        cout<<d<<" ";//0 2 3 8 6 9 
    }
    cout<<endl;


}

int main(){
    vector<vector<Edge>> graph(6);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph [1].push_back(Edge(2, 1));
    graph [1].push_back(Edge(3, 7));

     graph [2].push_back(Edge(4, 3));
    graph [3].push_back(Edge (5, 1));


    graph [4].push_back(Edge (3, 2));
   graph [4].push_back(Edge(2, 5));

   dijkstra(0,graph,6);

   return 0;

}

