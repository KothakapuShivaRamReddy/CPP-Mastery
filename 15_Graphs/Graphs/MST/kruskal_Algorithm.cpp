#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int wt;

    Edge(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};

class Graph{
    int V;
    vector<Edge> edges;
    vector<int> par;
    vector<int> rank;
    public:
      Graph(int v){
        this->V=v;  
        for(int i=0;i<v;i++){
            par.push_back(i);
            rank.push_back(0);
        }
      }
  

    void addEdge(int u,int v,int wt){
        edges.push_back( Edge(u,v,wt));
       
    }

    int find(int x){
    if(par[x]==x){
        return x;
    }
    return par[x]=find(par[x]);  //path compression
       }

    void unionByRank(int a,int b){
      int parA=find(a);
      int parB=find(b);

      if(rank[parA]==rank[parB]){
          par[parB]=parA;
          rank[parA]++;
      }else if(rank[parA]>rank[parB]){
          par[parB]=parA;

      }else{
         par[parA]=parB;
      }}

    void kruskal(){
        //sort edges based on wt
        sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
            return a.wt<b.wt;});
        int minCost=0;
        for(Edge e:edges){
            int u=e.u;
            int v=e.v;
            int wt=e.wt;

            int parU=find(u);
            int parV=find(v);

            if(parU!=parV){
                minCost+=wt;
                unionByRank(parU,parV);
            }
        }
        cout<<"Minimum cost: "<<minCost<<endl;
    }
};


int main(){
    Graph graph(4);
   graph.addEdge(0, 1, 10);
   graph.addEdge(0, 2, 15);
   graph.addEdge(0, 3, 30);
   graph.addEdge (1, 3, 40);
   graph.addEdge(2, 3, 50);

   graph.kruskal();
   

   return 0;
}