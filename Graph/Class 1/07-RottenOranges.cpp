class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // row, col, time
        queue<pair<pair<int, int>, int>> q;

        // Visited matrix initialized to 0
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1; // Mark as visited
                }
            }
        }

        int tm = 0; // Maximum time to rot all oranges

        // Directions for moving up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            tm = max(time, tm);
            q.pop();

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                // Check boundaries and if the orange is fresh and unvisited
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1});
                    visited[nrow][ncol] = 1; // Mark as visited
                    grid[nrow][ncol] = 2; // Rotten the fresh orange
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; // Fresh orange left, impossible to rot all
                }
            }
        }

        return tm; // Return the time taken to rot all oranges
    }
};
