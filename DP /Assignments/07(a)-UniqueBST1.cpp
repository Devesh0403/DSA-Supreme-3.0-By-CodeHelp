int recursive(int n) {
        
        if(n<=1)return 1;

        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=recursive(i-1)*recursive(n-i);

        }
        return ans;

        
}
int memoization(int n,vector<int>&dp){
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];

        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=memoization(i-1,dp)*memoization(n-i,dp);

        }
        return dp[n]= ans;
    }