int recursive(vector<int>& coins, int index, int amount) {
        // base cases. When last iteration
        if (index == 0) {
            // if the first coin is divisbile by the amount return 1 as we
            // return count, else return 0
            return amount % coins[0] == 0;
        }

        // Take and not take cases
        int notTake = 0 + recursive(coins, index - 1, amount);
        int take = 0;
        // Declare take as 0 initially as the current coin might be smaller than current amount.
        if (coins[index] <= amount) {
            take = recursive(coins,index,amount-coins[index]);
        }

        return take+notTake;
}

int memoization(vector<int>& coins, int index, int amount,vector<vector<int>>&dp) {
        // base cases. When last iteration
        if (index == 0) {
            // if the first coin is divisbile by the amount return 1 as we
            // return count, else return 0
            return amount % coins[0] == 0;
        }

        //If already computed, then return it
        if(dp[index][amount]!=-1)return dp[index][amount];

        // Take and not take cases
        int notTake = 0 + memoization(coins, index - 1, amount,dp);
        int take = 0;
        // Declare take as 0 initially as the current coin might be smaller than current amount.
        if (coins[index] <= amount) {
            take = memoization(coins,index,amount-coins[index],dp);
        }

        return dp[index][amount]=take+notTake;
    }
long long tabulation(vector<int>& coins, int target) {
        int n = coins.size();

        // initialize a dp array
        vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));

        for (int t = 0; t <= target; t++) {
            dp[0][t] = (t % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                long long notTake = dp[ind-1][tar];;
                long long take = 0;
                // Declare take as 0 initially as the current coin might be
                // smaller than current amount.
                if (coins[ind] <= tar) {
                    take = dp[ind][tar - coins[ind]];
                }
                if (take + notTake > INT_MAX) {
                    return 0; // Or handle overflow as needed
                }


                dp[ind][tar] = take + notTake;
            }
        }
        return (int)dp[n-1][target];
    }

    long long spaceOptimized(vector<int>& coins, int target) {
        int n = coins.size();

        // initialize a dp array
        vector<long>prev(target+1,0),curr(target+1,0);

        for (int t = 0; t <= target; t++) {
            prev[t] = (t % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                long long notTake = prev[tar];;
                long long take = 0;
                // Declare take as 0 initially as the current coin might be
                // smaller than current amount.
                if (coins[ind] <= tar) {
                    take = curr[tar - coins[ind]];
                }
                if (take + notTake > INT_MAX) {
                    return 0; // Or handle overflow as needed
                }


                curr[tar] = take + notTake;
            }
            prev=curr;
        }
        return (int)prev[target];
    }