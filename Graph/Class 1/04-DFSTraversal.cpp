// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>
#include <queue>

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
    void BFSTraversal(int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        
        q.push(src);
        visited[src]=true;
        
        while(!q.empty()){
            int frontNode=q.front();
            cout<<frontNode<<" ";
            q.pop();
            
            for(auto neighbour:adjList[frontNode]){
                
                int node=neighbour.first;
                int weight=neighbour.second;
                
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                }
            }
            
        }
    }
    void DFSHelper(int src,unordered_map<int,bool>&visited){
        visited[src]=true;
        cout<<src<<",";
        
        for(auto nbr:adjList[src]){
            //nbr-pair
            int node=nbr.first;
            if(!visited[node]){
                DFSHelper(node,visited);
                
                
            }
            
        }
    }
    
    void DFSTraversal(int n){
        
        unordered_map<int,bool>visited;
       for(int src=0;src<n;src++){
           if(!visited[src]){
               DFSHelper(src,visited);
           }
       }
        
        // DFSHelper(src,visited);
        
    }
    
};

int main() {
    
    Graph g;
    g.addEdge(0,2,4,1);
    g.addEdge(0,3,4,1);
    g.addEdge(0,5,4,1);
    g.addEdge(3,5,4,1);
    g.addEdge(2,5,4,1);
    g.addEdge(5,6,4,1);
    g.addEdge(5,4,4,1);
    g.addEdge(4,1,4,1);
    g.addEdge(6,1,4,1);
    
    
    g.printList(7);
    
    // cout<<"BFS Traversal"<<endl;
    // g.BFSTraversal(0);
    
    cout<<"DFS Traversal"<<endl;
    
    g.DFSTraversal(7);
    
    
    
    
    

    return 0;
}