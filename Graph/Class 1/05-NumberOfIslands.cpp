class Solution {
public:
    void DFSTraversal(vector<vector<char>>& grid,vector<vector<bool>>&visited,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        if(row<0||row>n-1||col<0||col>m-1||grid[row][col]=='0'||visited[row][col]){
            return;
        }

        visited[row][col]=true;

        DFSTraversal(grid,visited,row+1,col);
        DFSTraversal(grid,visited,row-1,col);
        DFSTraversal(grid,visited,row,col+1);
        DFSTraversal(grid,visited,row,col-1);

        return;


    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows=grid.size();
        int cols=grid[0].size();
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));

        int count=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'&& !visited[i][j]){
                    count++;
                    DFSTraversal(grid,visited,i,j);
                }
            }
        }
        return count;

    }
};