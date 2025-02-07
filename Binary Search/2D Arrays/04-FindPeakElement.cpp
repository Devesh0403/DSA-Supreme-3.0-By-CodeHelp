class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int left = 0, right = cols - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;
            int maxRow = 0;

            // Find the row index of the maximum element in midCol
            for (int i = 0; i < rows; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            bool leftIsSmaller = (midCol == 0) || (mat[maxRow][midCol] > mat[maxRow][midCol - 1]);
            bool rightIsSmaller = (midCol == cols - 1) || (mat[maxRow][midCol] > mat[maxRow][midCol + 1]);

            // If it's a peak, return the position
            if (leftIsSmaller && rightIsSmaller) {
                return {maxRow, midCol};
            }

            // Move search space based on the neighboring column
            if (midCol > 0 && mat[maxRow][midCol - 1] > mat[maxRow][midCol]) {
                right = midCol - 1; // Move left
            } else {
                left = midCol + 1;  // Move right
            }
        }

        return {-1, -1}; 
        
    }
};