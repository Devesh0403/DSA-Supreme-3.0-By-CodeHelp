class DisjointSet {
private:
    vector<int> parent, size;

public:
    // Constructor to initialize parent and size
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // Initial size of each set is 1
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;  // Each node is its own parent initially
        }
    }

    // Function to find the ultimate parent of a node (with path compression)
    int findParent(int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node]);  // Path compression
        }
        return parent[node];
    }

    // Function to union two nodes by size
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;  // Already in the same set

        // Attach the smaller tree under the larger one
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
