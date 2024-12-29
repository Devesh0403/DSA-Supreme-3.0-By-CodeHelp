
class Solution {
  public:
  void topoBFS(int n,vector<vector<int>>& adj,vector<int>&ans){
        unordered_map<int,int>indegree;
        queue<int>q;
        
        for(int src=0;src<n;src++){
            for(auto nbr:adj[src]){
                indegree[nbr]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front=q.front();
            ans.push_back(front);
            
            for(auto nbr:adj[front]){
                indegree[nbr]--; 
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
            q.pop();
            
        }
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        
        vector<int>ans;
        topoBFS(adj.size(),adj,ans);
        return ans.size()!=adj.size();
        
        // code here
    }
};

