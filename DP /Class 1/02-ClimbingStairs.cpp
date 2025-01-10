//METHOD 1 - RECURSION
class Solution {
public:
    int recursion(int n){
        if(n<=1)return 1;

        return recursion(n-1)+recursion(n-2);
    }
    int fib(int n) {
        return recursion(n);
        
    }
};
// TC=O(2^N) 2 Recursive calls for each
// SC=O(N)   Auxiliary Recursive Stack Space 


// METHOD 2 - MEMOIZATION

int memoization(int n,vector<int>&dp){
        if(n<=1)return 1;

        if(dp[n]!=-1)return dp[n];


        return dp[n]=  memoization(n-1,dp)+memoization(n-2,dp);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return memoization(n,dp);
    }

// TC= O(N)
// SC= O(N)



// METHOD 3 - TABULATION
int tabulation(int n){
        if(n<=1)return 1;

        vector<int>dp(n+1,-1);
        dp[0]=1,dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        return tabulation(n);
    }
// TC= O(N)   n-2 iterations 
// SC= O(N)   


// METHOD 4 - SPACE OPTIMIZATION

class Solution {
public:
    int spaceOptimized(int n){
        if(n<=1)return n;

        int prev=0;
        int next=1;

        for(int i=2;i<=n;i++){
            int temp=prev+next;
            prev=next;
            next=temp;

        }
        return next;

        
    }
    int countWays(int n) {

        return spaceOptimized(n);
        
    }
};

// TC= O(N)  n-2 iterations 
// SC= O(1) Constant space because only 2 variables every time



