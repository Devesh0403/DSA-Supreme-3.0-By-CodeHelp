class Solution {
public:
    int memoization(int lastIndex, vector<int>& nums, int i,vector<vector<int>>& dp) {
        // base case
        if (i >= nums.size())
            return 0;

        int curr = nums[i];
        int inc = 0;

        //Step-2 : check if the solution is already present or not
        if (dp[lastIndex + 1][i] != -1)
            return dp[lastIndex + 1][i];

        //Step-3 :if lastindex == -1 i.e. it is the first element OR the element is greater than last then include it in the subsequence
        if (lastIndex == -1 || curr > nums[lastIndex]) {
            inc = 1 + memoization(i, nums, i + 1, dp);
        }
        //in every case exclude it as well
        int exc = 0 + memoization(lastIndex, nums, i + 1, dp);

        //Step-4 :return max of inc & exc and store in dp array
        return dp[lastIndex + 1][i] = max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        // step-1 Create and pass a 2D DP array
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, -1));

        // for first case
        int lastIndex = -1;

        int i = 0;
        return memoization(lastIndex, nums, i, dp);
    }
};