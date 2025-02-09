class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,int i,int j,int row,int col,int index){

        if(index>=word.size())return true;

        if (i < 0 || j < 0 || i == row || j == col || board[i][j] != 
        word[index] or board[i][j] == '!')
            return false;

        char c = board[i][j];
        board[i][j] = '!';

        bool left=helper(board,word,i-1,j,row,col,index+1);
        bool right=helper(board,word,i+1,j,row,col,index+1);
        bool top=helper(board,word,i,j-1,row,col,index+1);
        bool bottom=helper(board,word,i,j+1,row,col,index+1);

        board[i][j] = c;

        return right||left||top||bottom;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int row=board.size();
        int col=board[0].size();
        int index=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[index]){
                    if(helper(board,word,i,j,row,col,index))return true;
                }
            }
        }
        return false;
        
    }
};
// Time Complexity:  O(m*n*4^k)
// Space Complexity: O(K)