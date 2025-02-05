class Solution {
  public:
  int countSub(string s)
    {
        int n = s.size();

        // dp array to store counts
        vector<int> dp(n + 1, 0);

        // Empty string has one subsequence
        dp[0] = 1;

        // To store the last occurrence index of each
        // character
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {

            // Double the count from the previous position
            dp[i] = 2 * dp[i - 1];

            // If the current character has occurred before
            if (last[s[i - 1] - 97] != -1) {

                // Subtract the count of subsequences ending
                // at the last occurrence
                dp[i] = dp[i] - dp[last[s[i - 1] - 97]];
            }
            // Update the last occurrence index of the
            // current character
            last[s[i - 1] - 97] = i - 1;
        }

        // Return the total count of distinct subsequences
        return dp[n];
    }
    string betterString(string str1, string str2) {
        return countSub(str1)>=countSub(str2)?str1:str2;
        // code here
    }
};