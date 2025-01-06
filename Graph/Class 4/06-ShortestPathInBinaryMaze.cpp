class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1) {
            return grid[0][0] == 0 ? 1 : -1;
        }

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        pair<int,int>source={0,0};
        pair<int,int>destination={grid.size()-1,grid[0].size()-1};



        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0,1,-1,1,-1};
        int dc[] = {0, 1, 0, -1,1,1,-1,-1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 8; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = 1 + dis;
                    if (nrow == destination.first && ncol == destination.second)
                        return 1 + dis;

                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};