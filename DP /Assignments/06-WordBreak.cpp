bool recursive(string s,vector<string>&wordDict,int start){
        if(s.size()==start)return true;

        string word="";
        bool flag=false;

        for(int i =start;i<s.size();++i){
            word+=s[i];
            if(check(word,wordDict)){
                flag=flag||recursive(s,wordDict,i+1);
            }
        }
        return flag;




        //one case

    }

bool memoization(string s, vector<string>& wordDict, int start,
                     vector<int>& dp) {
        if (s.size() == start)
            return true;

        string word = "";
        bool flag = false;

        if (dp[start] != -1)
            return dp[start];

        for (int i = start; i < s.size(); ++i) {
            word += s[i];
            if (check(word, wordDict)) {
                flag = flag || memoization(s, wordDict, i + 1, dp);
            }
        }
        return dp[start] = flag;

        // one case
    }
bool tabulation(string s,vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 1);

        for (int start = s.size() - 1; start >= 0; start--) {
            string word = "";
            bool flag = false;

            for (int i = start; i < s.size(); ++i) {
                word += s[i];
                if (check(word, wordDict)) {
                    flag = flag || dp[i+1];
                }
            }
            dp[start]=flag;
        }
        return dp[0];
    }