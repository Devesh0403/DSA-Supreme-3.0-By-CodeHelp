//{ Driver Code Starts

class Solution {
  public:
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>distance(adj.size(),INT_MAX);
        distance[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                
                if(dis+edgeWeight<distance[adjNode]){
                    distance[adjNode]=dis+edgeWeight;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }
        return distance;
    }
};
