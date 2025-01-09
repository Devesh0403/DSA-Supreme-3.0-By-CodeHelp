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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        DisjointSet ds(V);


        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j])ds.unionBySize(i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            if(ds.findParent(i)==i)cnt++;
        }
        return cnt;

        
    }
};