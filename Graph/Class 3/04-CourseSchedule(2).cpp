class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        unordered_map<int, int> indegree;
        vector<int> ans;

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++; // Use indexing to access elements
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            ans.push_back(front);

            for (auto nbr : adj[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
            q.pop();
        }

        if(ans.size()==n)return ans;
        else return {};
        
    }
};