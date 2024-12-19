
class Solution {
  public:
   int recursive(vector<int>&val,vector<int>&wt,int W,int index,vector<vector<int>>&dp){
       if(index<0)return 0;
       
       if(dp[index][W]!=-1)return dp[index][W];
       
       if(wt[index]>W){
            dp[index][W]= recursive(val,wt,W,index-1,dp);
           
       }
       else {
            dp[index][W]= max(val[index]+recursive(val,wt,W-wt[index],index-1,dp),
           recursive(val,wt,W,index-1,dp));
       }
       
       return dp[index][W];
       
      
   }
   
    
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        vector<vector<int>>dp(val.size(),vector<int>(capacity+1,-1));
        
        return recursive(val,wt,capacity,wt.size()-1,dp);
        // code here
    }
};

