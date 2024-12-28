
class Solution {
  public:
   bool cycleDetectionUndirectedDFS(int i,unordered_map<int,bool>&visited,
   vector<vector<int>>& adj,int parent){
       
       visited[i]=true;
       
       for(auto nbr:adj[i]){
           if(!visited[nbr]){
               bool ans=cycleDetectionUndirectedDFS(nbr,visited,adj,i);
               if(ans==true)return true;
           }
           else if(visited[nbr]&&parent!=nbr)return true;
       }
       return false;
       
       
   }
    bool isCycle(vector<vector<int>>& adj) {
        
         unordered_map<int,bool>visited;
         bool ans=false;
         
         int v=adj.size();
         for(int i=0;i<v;i++){
             if(!visited[i]){
                 ans=cycleDetectionUndirectedDFS(i,visited,adj,-1);
                 if(ans==true)break;
                 
             }
         }
         return ans;
      
};

