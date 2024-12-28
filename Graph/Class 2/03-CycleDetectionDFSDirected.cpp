
class Solution {
  public:
    bool DFSHelper(int i,vector<vector<int>>&adj,
    unordered_map<int,bool>&visited,unordered_map<int,bool>&DFSTracker){
        visited[i]=true;
        DFSTracker[i]=true;
        
        for(auto nbr:adj[i]){
            if(!visited[nbr]){
                bool ans=DFSHelper(nbr,adj,visited,DFSTracker);
                if(ans==true)return true;
            }
            
            else if(visited[nbr]&&DFSTracker[nbr])return true;
        }
        DFSTracker[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        bool ans=false;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>DFSTracker;
        
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans=DFSHelper(i,adj,visited,DFSTracker);
                if(ans==true)return true;
                
            }
            
        }
        return false;
        // code here
    }
};
