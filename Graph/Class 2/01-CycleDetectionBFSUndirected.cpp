
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
