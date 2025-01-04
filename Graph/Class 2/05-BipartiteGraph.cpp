class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;

        vector<int> color(graph.size(), -1);
        int i = 0;

        for (int i = 0; i < graph.size(); ++i) {
            if (color[i] != -1)
                continue;

            q.push(i);
            color[i] = 0;

            while (!q.empty()) {

                int front = q.front();
                q.pop();

                for (auto nbr : graph[front]) {
                    if (color[nbr] == color[front])
                        return false;

                    else if (color[nbr] == -1) {
                        color[nbr] = 1 - color[front];
                        q.push(nbr);
                    }
                }
            }
        }
        return true;
    }
};