int recursive(vector<int>& prices, int index, bool buy) {
        //only 2 changes in the buy and sell stock 2 problem

        //Change 1- To increase the index by 2 when you sell the stock
        // Change 2- To change the base case to >=prices.size() so as to handle the overflow condition
        if (index >= prices.size())
            return 0;

        int profit=0;

        if (buy) {
            profit= max(-prices[index] + recursive(prices, index + 1, 0),
                       recursive(prices, index + 1, 1));
        }
        else{
            profit= max(prices[index] + recursive(prices, index + 2, 1),
                       recursive(prices, index + 1, 0));

        }
        return profit;

}
int memoization(vector<int>& prices, int index, bool buy,vector<vector<int>>&dp) {
        //only 2 changes in the buy and sell stock 2 problem

        //Change 1- To increase the index by 2 when you sell the stock
        // Change 2- To change the base case to >=prices.size() so as to handle the overflow condition
        if (index >= prices.size())
            return 0;

        int profit=0;

        if(dp[index][buy]!=-1)return dp[index][buy];

        if (buy) {
            dp[index][buy]= max(-prices[index] + memoization(prices, index + 1, 0,dp),
                       memoization(prices, index + 1, 1,dp));
        }
        else{
            dp[index][buy]= max(prices[index] + memoization(prices, index + 2, 1,dp),
                       memoization(prices, index + 1, 0,dp));

        }
        return dp[index][buy];

    }

    int maxProfit(vector<int>& prices) {
        // return recursive(prices,0,1);


        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return memoization(prices,0,1,dp);
        
    }
    

