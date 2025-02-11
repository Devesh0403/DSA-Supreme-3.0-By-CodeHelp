class Solution {
public:
    bool isValid(int col, int row, vector<string>& board, int n) {
        int r, c;

        // upper-left diagonal
        r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // lower-left diagonal
        r = row, c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }

        return true;
    }
    void solve(int col, vector<string>& board, int n,
               vector<vector<string>>& ans) {
        if (n == col) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {

            if (isValid(col, row, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        int col = 0;

        for (int i = 0; i < board.size(); i++) {
            board[i] = s;
        }
        solve(col, board, n, ans);
        return ans;
    }
};