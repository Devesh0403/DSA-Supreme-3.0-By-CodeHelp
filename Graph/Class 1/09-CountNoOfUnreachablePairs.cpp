class Solution {
public:
    void DFSHelper(vector<vector<int>>& adjList,int src, unordered_map<int, bool>& visited,long long&count) {
        visited[src] = true;
        // cout << src << ",";
        count++;

        for (auto nbr : adjList[src]) {
            // nbr-pair
            int node = nbr;
            if (!visited[node]) {
                DFSHelper(adjList,node, visited,count);
            }
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);

        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int, bool> visited;
        long long totalPairs = (long long)n * (n - 1) / 2;  // Total possible pairs
        long long reachablePairs = 0;

        
        for (int src = 0; src < n; src++) {
            long long count=0;
            if (!visited[src]) {
                DFSHelper(adjList,src, visited,count);
                
            }
            reachablePairs += count * (count - 1) / 2;
        }
        
        return totalPairs-reachablePairs;
    }
};