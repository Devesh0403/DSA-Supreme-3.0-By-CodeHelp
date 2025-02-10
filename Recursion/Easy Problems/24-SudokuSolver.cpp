class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == digit || board[i][col] == digit ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(board, i, j, digit)) {
                            board[i][j] = digit;
                            bool solved = solve(board); // for rest of the board

                            if (solved == true) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};