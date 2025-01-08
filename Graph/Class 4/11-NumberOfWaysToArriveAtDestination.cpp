class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> distance(n, LLONG_MAX);  // Use long long to avoid overflow
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        pq.push({0, 0});  // {distance, node}
        distance[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > distance[node]) continue;  // Skip if this is not the shortest known path

            for (auto& nbr : adj[node]) {
                int adjNode = nbr.first;
                int weight = nbr.second;

                if (dis + weight < distance[adjNode]) {
                    distance[adjNode] = dis + weight;
                    ways[adjNode] = ways[node];
                    pq.push({distance[adjNode], adjNode});
                } else if (dis + weight == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
        
    }
};