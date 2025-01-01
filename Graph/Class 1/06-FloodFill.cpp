class Solution {
public:
    void DFSTraversal(vector<vector<int>>& image, int row, int col, int color,int prev) {

        if (row < 0 || row > image.size() - 1 ||
            col < 0 || col > image[0].size() - 1 || image[row][col] != prev )
            return;


        image[row][col] = color;

        DFSTraversal(image, row, col + 1, color, prev);
        DFSTraversal(image, row + 1, col, color, prev);
        DFSTraversal(image, row, col - 1, color, prev);
        DFSTraversal(image, row - 1, col, color, prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if (image[sr][sc] == color) {
            return image;
        }

        DFSTraversal(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};