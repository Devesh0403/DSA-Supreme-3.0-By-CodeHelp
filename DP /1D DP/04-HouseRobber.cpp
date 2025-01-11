int recursion(vector<int>&arr,int index){
        if(index==0)return arr[0];
        if (index < 0) return 0;
        
        int notPick=0+recursion(arr,index-1);
        
        int pick=arr[index]+recursion(arr,index-2);
        
        return max(pick,notPick);
    }
    int findMaxSum(vector<int>& arr) {
        
        return recursion(arr,arr.size()-1);
        
        // code here
    }


    int memoization(vector<int>&arr,int index,vector<int>&dp){
        if(index==0)return arr[0];
        if (index < 0) return 0;
        
        if (dp[index] != -1)
        return dp[index];

        
        int notPick=0+memoization(arr,index-1,dp);
        
        int pick=arr[index]+memoization(arr,index-2,dp);
        
        return dp[index]=max(pick,notPick);
    }
    int findMaxSum(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        
        return memoization(arr,arr.size()-1,dp);
        
        // code here
    }