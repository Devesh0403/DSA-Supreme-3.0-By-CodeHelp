//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool cycleDetectionUndirectedBFS(int src, unordered_map<int,bool>&visited,
    vector<vector<int>>& adjList){
        queue<pair<int,int>>q;
       
        
        q.push({src,-1});
        visited[src]=true;
       
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            
            q.pop();
            
            for(auto nbr:adjList[node]){
                if(!visited[nbr]){
                    q.push({nbr,node});
                    visited[nbr]=true;
        
                }
               else if(parent!=nbr){
                   return true;
               }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        
         unordered_map<int,bool>visited;
         bool ans=false;
         
         int v=adj.size();
         for(int i=0;i<v;i++){
             if(!visited[i]){
                 ans=cycleDetectionUndirectedBFS(i,visited,adj);
                 if(ans==true)break;
                 
             }
         }
         return ans;
        
        
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends