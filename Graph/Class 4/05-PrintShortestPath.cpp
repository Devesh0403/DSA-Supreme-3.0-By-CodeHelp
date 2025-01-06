
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<m;i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1,0);
        
        dist[1] = 0;
        
        for(int i=1;i<=n;i++) parent[i] = i;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int d = curr.first;
            int u = curr.second;
            
            for(auto it : adj[u]){
                
                int node = it.first;
                int wt = it.second;
                
                if(d + wt < dist[node]){
                    dist[node] = d + wt;
                    parent[node] = u;
                    pq.push({dist[node],node});
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> res;

        int node = n;
        
        while(parent[node] != node){
            
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(1);
        res.push_back(dist[n]);
        reverse(res.begin(),res.end());
        return res;
        
        
        
        
        
        // Code here
        
    }
};
