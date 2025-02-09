class Solution {
  public:
    void helper(vector<vector<int>>&mat,int row,int col,int m,int n,string path,vector<string>&ans,vector<vector<bool>>&visited){
        
        if(row>=m||row<0||col<0||col>=n||visited[row][col]||mat[row][col]==0)return;
        if (row == m - 1 && col == n - 1) {
          ans.push_back(path);
          return;
        }
        
        visited[row][col]=1;
        
        helper(mat,row,col+1,m,n,path+'R',ans,visited);
        helper(mat,row,col-1,m,n,path+'L',ans,visited);
        helper(mat,row+1,col,m,n,path+'D',ans,visited);
        helper(mat,row-1,col,m,n,path+'U',ans,visited);
        
        visited[row][col]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        
        vector<string>ans;
        string path="";
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector < vector < bool >> visited(m, vector < bool > (n, 0));
        
        if (mat[0][0] == 1) helper(mat,0,0,m,n,path,ans,visited);
        return ans;
        
        
        // code here
    }
};

// Time Complexity: O(4^(m*n))

// Space Complexity:  O(m*n)