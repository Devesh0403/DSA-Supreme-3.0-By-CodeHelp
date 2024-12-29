// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>

class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    
    void addEdge(int u,int v, bool direction){
        //direction ==0 =>undirected
        //direction ==1 =>directed
        if(direction==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }
    
    void printList(int n){
        for(int i=0;i<n;i++){
            cout<<i<<": {";
            list<int>temp=adjList[i];
            for(auto j:temp){
                cout<<j<<" ";
            }
            cout<<"}"<<endl;
        }
    }
    
};

int main() {
    
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    
    g.printList(4);
    
    
    
    

    return 0;
}