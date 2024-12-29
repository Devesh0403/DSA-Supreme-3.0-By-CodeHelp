
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void topoDFS(int i,unordered_map<int,bool>&visited,
    vector<int>&ans,vector<vector<int>>& adj){
        
        visited[i]=true;
        for(auto nbr:adj[i]){
            if(!visited[nbr]){
                topoDFS(nbr,visited,ans,adj);
            }
        }
        
        ans.push_back(i);
        
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        unordered_map<int,bool>visited;
        vector<int>ans;
        
        
        int n=adj.size();
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topoDFS(i,visited,ans,adj);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // Your code here
    }
};

