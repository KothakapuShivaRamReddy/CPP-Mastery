

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

    
    void calindegree(vector<int> &indeg){
        for(int u=0;u<V;u++){
            list<int> neighbours=l[u];
            for(int v:neighbours){
                indeg[v]++;
            }
        }
    }
    void topoSort(){//kahn's algorithm
        vector<int> indeg(V,0);
        calindegree(indeg);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
               q.push(i);
            }
        }

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            list<int> neighbours=l[curr];
            for(int v:neighbours){
                indeg[v]--;
                if(indeg[v]==0){//no dependencies
                    q.push(v);
                }
            }
        }
        cout<<endl;
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
