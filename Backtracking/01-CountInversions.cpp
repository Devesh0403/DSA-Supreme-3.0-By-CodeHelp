// METHOD - 1 RECURSION
class Solution {
    public:
      int recurrence(int day,int last,vector<vector<int>>&points){
          if(day==0){
              int maxi=0;
              for(int i=0;i<3;i++){
                  if(i!=last){
                      maxi=max(maxi,points[0][i]);
                  }
                  
              }
              return maxi; 
          }
          int maxi=0;
          for(int i=0;i<3;i++){
                  if(i!=last){
                      int point=points[day][i]+recurrence(day-1,i,points);
                      maxi=max(maxi,point);
                      
                  }
          }
          return maxi;
      }
      int maximumPoints(vector<vector<int>>& arr, int n) {
          return recurrence(n-1,3,arr);
      }
  };

  // TC - O(3^N)
  // SC - O(N)


  int memoization(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
            
        }
        return maxi;
        
        
    }
    if(dp[day][last]!=-1)return dp[day][last];
    
    int maxi=0;
    for(int i=0;i<3;i++){
            if(i!=last){
                int point=points[day][i]+memoization(day-1,i,points,dp);
                maxi=max(maxi,point);
                
            }
            
            
    }
    return dp[day][last]=maxi;
    
}
int maximumPoints(vector<vector<int>>& arr, int n) {
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return memoization(n-1,3,arr,dp);
    // Code here
}