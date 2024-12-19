int recursive(vector<int>&sv,int i){
        if(i==sv.size())return 0;
        
        int ans=INT_MIN;
        int total=0;

        for(int x=1;x<=3;x++){
            if(i+x-1>=sv.size())break;

            total+=sv[i+x-1];
            ans=max(ans,total-recursive(sv,i+x));



        }
        return ans;
    }

    int memoization(vector<int>& sv, int i, vector<int>& dp) {
        if (i == sv.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN;
        int total = 0;

        for (int x = 1; x <= 3; x++) {
            if (i + x - 1 >= sv.size())
                break;

            total += sv[i + x - 1];
            ans = max(ans, total - memoization(sv, i + x, dp));
        }
        return dp[i] = ans;
    }
    int tabulation(vector<int>& sv) {
        vector<int> dp(sv.size() + 1, 0);

        for (int i = sv.size() - 1; i >= 0; i--) {

            int ans = INT_MIN;
            int total = 0;

            for (int x = 1; x <= 3; x++) {
                if (i + x - 1 >= sv.size())
                    break;

                total += sv[i + x - 1];
                ans = max(ans, total - dp[i+x]);
            }
            dp[i]=ans;

        }
        return dp[0];
    }