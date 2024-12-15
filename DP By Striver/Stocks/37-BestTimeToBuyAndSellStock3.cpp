int recursive(vector<int>&prices,int index,int buy,int cap){
        if(index==prices.size()||cap==0)return 0;

        if(buy){
            return max(-prices[index]+recursive(prices,index+1,0,cap),
            recursive(prices,index+1,1,cap));
        }
        else{
            return max(prices[index]+recursive(prices,index+1,1,cap-1),
            recursive(prices,index+1,0,cap));
        }
    }
int recursive(vector<int>&prices,int index,int buy,int cap){
        if(index==prices.size()||cap==0)return 0;

        if(buy){
            return max(-prices[index]+recursive(prices,index+1,0,cap),
            recursive(prices,index+1,1,cap));
        }
        else{
            return max(prices[index]+recursive(prices,index+1,1,cap-1),
            recursive(prices,index+1,0,cap));
        }
    }
    int memoization(vector<int>&prices,int index,int buy,int cap,vector<vector<vector<int>>>&dp){
        if(index==prices.size()||cap==0)return 0;

        if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];

        if(buy){
            return dp[index][buy][cap]= max(-prices[index]+memoization(prices,index+1,0,cap,dp),
            memoization(prices,index+1,1,cap,dp));
        }
        else{
            return dp[index][buy][cap]= max(prices[index]+memoization(prices,index+1,1,cap-1,dp),
            memoization(prices,index+1,0,cap,dp));
        }
    }
    int maxProfit(vector<int>& prices,int k) {
        // return recursive(prices,0,1,k);

        // int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return memoization(prices,0,1,k,dp);


        
    }