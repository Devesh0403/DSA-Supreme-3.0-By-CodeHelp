int memoization(vector<int>& prices, int index, int buy, int cap,
                    vector<vector<vector<int>>>& dp) {
        if (index == prices.size() || cap == 0)
            return 0;

        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        if (buy) {
            return dp[index][buy][cap] =
                       max(-prices[index] +
                               memoization(prices, index + 1, 0, cap, dp),
                           memoization(prices, index + 1, 1, cap, dp));
        } else {
            return dp[index][buy][cap] =
                       max(prices[index] +
                               memoization(prices, index + 1, 1, cap - 1, dp),
                           memoization(prices, index + 1, 0, cap, dp));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return memoization(prices,0,1,k,dp);

    }