
class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < V; ++i) {
            for (auto& it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                if (i < adjNode) {
                    edges.emplace_back(wt, i, adjNode); // Store edge only once
                }
            }
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstWt = 0;

        for (auto& [wt, u, v] : edges) {
            if (ds.findParent(u) != ds.findParent(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};
