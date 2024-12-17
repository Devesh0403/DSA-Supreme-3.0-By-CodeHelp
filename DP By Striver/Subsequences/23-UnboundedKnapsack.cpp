class Solution {
  public:
    int memoization(vector<int>&val,vector<int>&wt,int index,int capacity,vector<vector<int>>&dp){
        if(index==0){
            return ((int)(capacity/wt[0]))*val[0];
        }
        
        if(dp[index][capacity]!=-1)return dp[index][capacity];
        
        int notTake=0+memoization(val,wt,index-1,capacity,dp);
        int take=INT_MIN;
        if(wt[index]<=capacity){
            take=val[index]+memoization(val,wt,index,capacity-wt[index],dp);
        }
        
        return dp[index][capacity]= max(take,notTake);
    
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return memoization(val,wt,n-1,capacity,dp);
    }
};
