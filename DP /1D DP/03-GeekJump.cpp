// METHOD 1 - RECURSIVE
class Solution {
  public:
    int recursive(int index,vector<int>&height){
        if(index==0)return 0;
        if(index==1)return abs(height[index]-height[index-1]);
        
        int left=recursive(index-1,height)+abs(height[index]-height[index-1]);
        int right=0;
        if(index>1){
            right=recursive(index-2,height)+abs(height[index]-height[index-2]);
        }
        
        return min(left,right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        return recursive(n,height);
        // Code here
    }
};
// Time Complexity: O(2^N)
// Space Complexity: O(N)

//METHOD 2 - MEMOIZATION
int memoization(vector<int>&height,int index,vector<int>&dp){
        
        if(index==0)return 0;
        if(dp[index]!=-1)return dp[index];
        int twoJumps=INT_MAX;
        int oneJump=memoization(height,index-1,dp)+abs(height[index]-height[index-1]);
        
        if(index>1)twoJumps=memoization(height,index-2,dp)+abs(height[index]-height[index-2]);
        
        return dp[index]=  min(oneJump,twoJumps);
        
        
    }
    int minCost(vector<int>& height) {
        int index=height.size()-1;
        vector<int>dp(index+1,-1);
        return memoization(height,index,dp);
        
    }

// Time Complexity: O(N)
// Space Complexity: O(N)



//METHOD 3 - TABULATION

int tabulation(vector<int>&height,int index){
        vector<int>dp(index,-1);
        dp[0]=0;
        
        for(int i=1;i<index;i++ ){
            int oneJump=dp[i-1]+abs(height[i]-height[i-1]);
            int twoJumps=INT_MAX;
            if(i>1){
                twoJumps=dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(oneJump,twoJumps);
        }
        return dp[index-1];
    }
    int minimumEnergy(vector<int>& height, int n) {
        
        return tabulation(height,n);
        // Code here
    }
// Time Complexity: O(N)
// Space Complexity: O(N)


//METHOD 4 - SPACE OPTIMIZED
int spaceOptimized(vector<int>&height,int index){
        int prev1=0;
        int prev2=0;
        
        for(int i=1;i<index;i++ ){
            int oneJump=prev1+abs(height[i]-height[i-1]);
            int twoJumps=INT_MAX;
            if(i>1){
                twoJumps=prev2+abs(height[i]-height[i-2]);
            }
            int cur_i=min(oneJump, twoJumps);
            prev2=prev1;
            prev1=cur_i;
        }
        return prev1;
    }
    int minimumEnergy(vector<int>& height, int n) {
        
        return spaceOptimized(height,n);
        // Code here
    }

// Time Complexity: O(N)
// Space Complexity: O(1)