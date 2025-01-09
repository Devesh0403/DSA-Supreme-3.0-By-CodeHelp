class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();

        vector<vector<pair<int,int>>>adj(points.size());
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
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
                int adjNode=nbr.first;
                int edgeWeight=nbr.second;
                
                if(!visited[adjNode])pq.push({edgeWeight,adjNode});
            }
            
        }
        return sum;

        
    }
};