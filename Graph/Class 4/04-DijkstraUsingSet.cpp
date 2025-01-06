
class Solution {
  public:
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
        set<pair<int,int>>st;
        vector<int>distance(adj.size(),INT_MAX);
        distance[src]=0;
        
        st.insert({0,src});
        
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto it:adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                
                if(dis+edgeWeight<distance[adjNode]){
                    if(distance[adjNode]!=INT_MAX){
                        st.erase({distance[adjNode],adjNode});
                    }
                    distance[adjNode]=dis+edgeWeight;
                    st.insert({distance[adjNode],adjNode});
                }
            }
        }
        return distance;
    }
};

