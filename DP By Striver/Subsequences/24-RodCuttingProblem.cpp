int recursive(vector<int>&price,int index,int n){
        //base case
        if(index==0){
            return n*price[0];
            
        }
        //Take and not take conditions
        int notTake=0+recursive(price,index-1,n);
        
        int take=INT_MIN;
        int rodLength=index+1;
        if(rodLength<=n){
            take=price[index]+recursive(price,index,n-rodLength);
        }
        
        return max(take,notTake);
    }

    int memoization(vector<int>&price,int index,int n,vector<vector<int>>&dp){
        //base case
        if(index==0){
            return n*price[0];
            
        }
        if(dp[index][n]!=-1)return dp[index][n];
        //Take and not take conditions
        int notTake=0+memoization(price,index-1,n,dp);
        
        int take=INT_MIN;
        int rodLength=index+1;
        if(rodLength<=n){
            take=price[index]+memoization(price,index,n-rodLength,dp);
        }
        
        return dp[index][n]= max(take,notTake);
    }
    int tabulation(vector<int>&price){
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        
        for(int N=0;N<=n;N++)dp[0][N]=N*price[0];
        
        for(int index=1;index<n;index++){
            for(int N=0;N<=n;N++){
                int notTake=0+dp[index-1][N];
                int take=INT_MIN;
                int rodLength=index+1;
                if(rodLength<=N){
                    take=price[index]+dp[index][N-rodLength];
                    
                }
                dp[index][N]= max(take,notTake);
                
            }
        }
        return dp[n-1][n];
    }
    int spaceOptimized(vector<int>&price){
        int n=price.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,0));
        
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        
        for(int N=0;N<=n;N++)prev[N]=N*price[0];
        
        for(int index=1;index<n;index++){
            for(int N=0;N<=n;N++){
                int notTake=0+prev[N];
                int take=INT_MIN;
                int rodLength=index+1;
                if(rodLength<=N){
                    take=price[index]+curr[N-rodLength];
                    
                }
                curr[N]= max(take,notTake);
                
            }
            prev=curr;
        }
        return prev[n];
    }