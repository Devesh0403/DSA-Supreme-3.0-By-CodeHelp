// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;
    
    void addEdge(int u,int v,int weight, bool direction){
        //direction ==0 =>undirected
        //direction ==1 =>directed
        if(direction==0){
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        else{
            adjList[u].push_back({v,weight});
        }
    }
    
    void printList(int n){
        for(int i=0;i<n;i++){
            cout<<i<<": {";
            list<pair<int,int>>temp=adjList[i];
            for(auto j:temp){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<"}"<<endl;
        }
    }
    
};

int main() {
    
    Graph g;
    g.addEdge(0,1,4,1);
    g.addEdge(0,2,5,1);
    g.addEdge(1,2,2,1);
    g.addEdge(2,3,7,1);
    
    g.printList(4);
    
    
    
    

    return 0;
}