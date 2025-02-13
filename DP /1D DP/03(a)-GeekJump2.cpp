  // METHOD 1 - RECURSIVE
  int K;
  int memoization(vector<int>&height,int index,vector<int>&dp){
        
        if(index==0)return 0;
        if(dp[index]!=-1)return dp[index];
        int mini=INT_MAX;
        for(int j=K;j>0;j--){
            if(index-j>=0){
                int jumps=memoization(height,index-j,dp)+ abs(height[index] - height[index - j]);
                
                mini=min(mini,jumps);
            }
        }
        return dp[index]=  mini;
        
        
    }
    int minimizeCost(int k, vector<int>& height) {
        K=k;
        int index=height.size();
        vector<int>dp(index,-1);
        return memoization(height,index-1,dp);
        
        // Code here
    }
    // Time Complexity: O(K^n)
    // Space Complexity: O(N)
  
  
  //METHOD 2 - MEMOIZATION
  int K;
  int memoization(vector<int>&height,int index,vector<int>&dp){
        
        if(index==0)return 0;
        if(dp[index]!=-1)return dp[index];
        int mini=INT_MAX;
        for(int j=K;j>0;j--){
            if(index-j>=0){
                int jumps=memoization(height,index-j,dp)+ abs(height[index] - height[index - j]);
                
                mini=min(mini,jumps);
            }
        }
        return dp[index]=  mini;
        
        
    }
    int minimizeCost(int k, vector<int>& height) {
        K=k;
        int index=height.size();
        vector<int>dp(index,-1);
        return memoization(height,index-1,dp);
        
        // Code here
    }

    // Time Complexity: O(K*n)
    // Space Complexity: O(N)
  