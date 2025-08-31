class Solution {
public:
    bool recursion(string &s, int index, int count, vector<vector<int>> &dp) {
        if (count < 0) return false;  // too many ')'
        if (index == s.size()) return count == 0;

        if (dp[index][count] != -1) return dp[index][count];

        bool res = false;
        if (s[index] == '(') {
            res = recursion(s, index + 1, count + 1, dp);
        }
        else if (s[index] == ')') {
            res = recursion(s, index + 1, count - 1, dp);
        }
        else { // '*'
            res = recursion(s, index + 1, count + 1, dp) ||  // treat '*' as '('
                  recursion(s, index + 1, count - 1, dp) ||  // treat '*' as ')'
                  recursion(s, index + 1, count, dp);        // treat '*' as empty
        }

        return dp[index][count] = res;
    }

    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return recursion(s, 0, 0, dp);
    }
};
