int recursive(vector<int>& coins, int index, int amount,vector) {
        if (amount == 0) return 0;
        if (index == 0) {

            if (amount % coins[index] == 0)
                return amount / coins[index];
            else {
                return INT_MAX;
            }
        }
        // if (index < 0 || amount < 0) return INT_MAX;

        int notTake = 0+recursive(coins, index - 1, amount);
        int take=INT_MAX;
        if(coins[index]<=amount){
            int res = recursive(coins, index, amount - coins[index]);
            if (res != INT_MAX) take = 1 + res;
        }
        return min(take,notTake);
    }


    int memoization(vector<int>& coins, int index, int amount) {
        if (amount == 0) return 0;
        if (index == 0) {

            if (amount % coins[index] == 0)
                return amount / coins[index];
            else {
                return INT_MAX;
            }
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        // if (index < 0 || amount < 0) return INT_MAX;

        int notTake = 0+memoization(coins, index - 1, amount);
        int take=INT_MAX;
        if(coins[index]<=amount){
            int res = memoization(coins, index, amount - coins[index]);
            if (res != INT_MAX) take = 1 + res;
        }
        return dp[index][amount]=min(take,notTake);
    }