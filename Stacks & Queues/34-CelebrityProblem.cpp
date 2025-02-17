// BRUTE FORCE - USING 2 LOOPS
class Solution {
    public:
      // Function to find if there is a celebrity in the party or not.
      int celebrity(vector<vector<int> >& mat) {
          int n=mat.size();
          
          vector<int>indegree(n,0);
          vector<int>outdegree(n,0);
          
          for(int row=0;row<mat.size();row++){
              for(int col=0;col<mat[0].size();col++){
                  indegree[col]+=mat[row][col];
                  outdegree[row]+=mat[row][col];
              }
          }
          
          for(int i=0;i<n;i++){
              if(indegree[i]==n-1&&outdegree[i]==0)return i;
          }
          return -1;
          // code here
      }
  };

  // TC - O(N^2)
  // SC - O(2*N)


  // OPTIMAL APPROACH - USING STACK
  class Solution {
    public:
      bool knows(int a,int b,vector<vector<int> >& mat){
          return mat[a][b]==1;
      }
      int celebrity(vector<vector<int> >& mat) {
          int n=mat.size();
          stack<int>st;
          for(int i=0;i<n;i++){
              st.push(i);
          }
          
          while(st.size()>1){
              int a=st.top();
              st.pop();
              int b=st.top();
              st.pop();
              if(knows(a,b,mat))st.push(b);
              else st.push(a);
          }
          int x=st.top();
          
          for (int i = 0; i < n; i++) {
          if (i != x && (mat[x][i] == 1 || mat[i][x] == 0)) {
              return -1; 
          }
      }
          return x;
          // code here
      }
  };

  // TC - O(N)
  // SC - O(N)
