class Solution {
public:
    int recursive(vector<int>& prices, int index, bool buy) {
        if (index == prices.size())
            return 0;

        int profit=0;

        if (buy) {
            profit= max(-prices[index] + recursive(prices, index + 1, 0),
                       recursive(prices, index + 1, 1));
        }
        else{
            profit= max(prices[index] + recursive(prices, index + 1, 1),
                       recursive(prices, index + 1, 0));

        }
        return profit;

    }

    int memoization(vector<int>& prices, int index, bool buy,vector<vector<int>>&dp) {
        if (index == prices.size())
            return 0;

        int profit=0;

        if(dp[index][buy]!=-1)return dp[index][buy];


        if (buy) {
            profit= max(-prices[index] + memoization(prices, index + 1, 0,dp),
                       memoization(prices, index + 1, 1,dp));
        }
        else{
            profit= max(prices[index] + memoization(prices, index + 1, 1,dp),
                       memoization(prices, index + 1, 0,dp));

        }
        return dp[index][buy]= profit;

    }
    int tabulation(vector<int>& prices, int n) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                long profit=0;
                if (buy) {
                    profit = max(-prices[ind] +
                                     dp[ind+1][0],
                                 dp[ind+1][1]);
                } else {
                    profit = max(prices[ind] +
                                     dp[ind+1][1],
                                 dp[ind+1][0]);
                }
            dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }

    int spaceOptimized(vector<int>& prices, int n) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

        vector<int>ahead(2,0);
        vector<int>curr(2,0);

        // ahead[0] = ahead[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                long profit=0;
                if (buy) {
                    profit = max(-prices[ind] +
                                     ahead[0],
                                 ahead[1]);
                } else {
                    profit = max(prices[ind] +
                                     ahead[1],
                                 ahead[0]);
                }
            curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }

    
    int maxProfit(vector<int>& prices) {
        //recursive
         return recursive(prices, 0, 1); 


    }
};