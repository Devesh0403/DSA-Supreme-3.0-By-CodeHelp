// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<list>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    
    void addEdge(int u,int v,int direction){
        if(direction==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }
    
    void print(int n){
        for(int i=0;i<n;i++){
            cout<<i<<" : { ";
            for(auto j:adjList[i]){
                cout<<j<<" ";
            }
            
            cout<<" }"<<endl;
        }
    }
    
    void shortestPathBFS(int src,int dest){
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto nbr:adjList[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=front;
                }
            }
        }
        vector<int>path;
        
        int node=dest;
        
        while(node!=-1){
            path.push_back(node);
            node=parent[node];
        }
        
        reverse(path.begin(),path.end());
        cout<<"Path is"<<endl;
        for(auto i:path){
            cout<<i<<"->";
        }
        
        
    }
};

int main() {
    Graph g;
    
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);
    
    
    
    g.print(5);
    
    
    g.shortestPathBFS(0,3);
    
    
}