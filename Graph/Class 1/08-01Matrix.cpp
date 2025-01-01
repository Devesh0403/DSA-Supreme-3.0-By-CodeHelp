class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>distance(mat.size(),vector<int>(mat[0].size(),INT_MAX));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    distance[i][j]=0;
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;

            int dist=q.front().second;

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0&& nrow<n&& ncol>=0&&ncol<m&& !visited[nrow][ncol]){
                    distance[nrow][ncol]=dist+1;
                    visited[nrow][ncol]=1;
                    q.push({{nrow, ncol}, dist + 1});
                }
            }

            q.pop();


        }
        return distance;


        
    }
};