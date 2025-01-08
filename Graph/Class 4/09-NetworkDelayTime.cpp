class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : times) {
            //{node,distance}
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> distance(adj.size(), INT_MAX);
        distance[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;

                if (dis + edgeWeight < distance[adjNode]) {
                    distance[adjNode] = dis + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX)
                return -1;

            else if(maxi<distance[i])maxi=distance[i];
        }

        return maxi;
    }
};