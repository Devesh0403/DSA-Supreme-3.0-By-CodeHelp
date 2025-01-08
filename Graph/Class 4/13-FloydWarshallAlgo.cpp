
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        
        int a=mat.size();
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(mat[i][j]==-1){
                    mat[i][j]=INT_MAX;
                }
                if(i==j)mat[i][j]=0;
            }
        }
        
        for(int k=0;k<a;k++){
            for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
            }
        }
        }
        
        
        
        
        
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(mat[i][j]==INT_MAX){
                    mat[i][j]=-1;
                }
            }
        }
        return;
        
        // Code here
    }
};

