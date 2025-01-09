
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<bool>visited(V,false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int sum=0;
        // visited[0]=1;
            
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            
            if(visited[node])continue;
            
            sum+=wt;
            visited[node]=1;
            for(auto nbr:adj[node]){
                int adjNode=nbr[0];
                int edgeWeight=nbr[1];
                
                if(!visited[adjNode])pq.push({edgeWeight,adjNode});
            }
            
        }
        return sum;
        // code here
    }
};
