class Solution {
public:
int LCSMemoization(int index1,int index2,string&s1,string&s2,vector<vector<int>>&dp){
        if(index1<0||index2<0){
            return 0;
        }
        if(dp[index1][index2]!=-1)return dp[index1][index2];

        if(s1[index1]==s2[index2]){
            return  dp[index1][index2]= 1+LCSMemoization(index1-1,index2-1,s1,s2,dp);
        }

        return dp[index1][index2]= max(LCSMemoization(index1-1,index2,s1,s2,dp),LCSRMemoization(index1,index2-1,s1,s2,dp));
    }
    int LCSRecursive(int index1,int index2,string s1,string s2){
        if(index1<0||index2<0){
            return 0;
        }
        if(s1[index1]==s2[index2]){
            return 1+LCSRecursive(index1-1,index2-1,s1,s2);
        }

        return max(LCSRecursive(index1-1,index2,s1,s2),LCSRecursive(index1,index2-1,s1,s2));
    }
    
    int LCSTabulation(string& s1, string& s2) {
        
        int n=s1.length();
        int m=s2.length();
        
        int maxLength=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxLength=max(maxLength,dp[i][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return maxLength;
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m=text1.size();
        int n=text2.size();

        // return LCSRecursive(m-1,n-1,text1,text2);

        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return LCSMemoization(m-1,n-1,text1,text2,dp);




        
    }
};