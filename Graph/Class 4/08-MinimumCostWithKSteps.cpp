class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        
        // {stops,{node,dist}}
        queue<pair<int,pair<int,int>>>q;

        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);

        for(auto edge:flights){
            //{node,distance}
            adj[edge[0]].push_back({edge[1],edge[2]});
            

        }

        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();

            if(stops>k)continue;

            for(auto nbr:adj[node]){
                int adjNode=nbr.first;
                int edgeWeight=nbr.second;

                if(cost+edgeWeight<dist[adjNode]&&stops<=k){

                    dist[adjNode]=cost+edgeWeight;
                    q.push({stops+1,{adjNode,dist[adjNode]}});

                }
            }
        }

        if(dist[dst]==INT_MAX)return -1;
        
        return dist[dst];


    }
};