
class Solution {
  public:
   bool memoization(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
        //base case
        if(target==0){
            return true;
        }
        
        if(index==0||target<0){
            return false;
        }

        //one case we'll solve
        
        if(dp[index][target]!=-1)return dp[index][target];
        
        

        bool inc=memoization(nums,index-1,target-nums[index-1],dp);
        bool exc=memoization(nums,index-1,target,dp);
        
        return dp[index][target]=inc||exc;


    }
    bool isSubsetSum(vector<int>& arr, int target) {
        
        vector<vector<int>>dp(arr.size() + 1,vector<int>(target + 1,-1));
        if(arr.size()==0) return 0;

        
        return memoization(arr,arr.size(),target,dp);
        // code here
    }
};

