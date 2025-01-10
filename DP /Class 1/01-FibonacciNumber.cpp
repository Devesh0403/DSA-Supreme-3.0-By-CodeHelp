//METHOD 1 - RECURSION
class Solution {
public:
    int recursion(int n){
        if(n<=1)return n;

        return recursion(n-1)+recursion(n-2);
    }
    int fib(int n) {
        return recursion(n);
        
    }
};
// TC=O(2^N) 2 Recursive calls for each
// SC=O(N)   Auxiliary Recursive Stack Space 


// METHOD 2 - MEMOIZATION

class Solution {
public:
    int memoization(int n,vector<int>&memo){
        if(n<=1)return n;

        if(memo[n]!=-1)return memo[n];

        return memo[n]=memoization(n-1,memo)+memoization(n-2,memo);
    }
    int fib(int n) {

        vector<int>memo(n+1,-1);
        return memoization(n,memo);
        
    }
};

// TC= O(N)
// SC= O(N)



// METHOD 3 - TABULATION
class Solution {
public:
    int tabulation(int n){
        if(n<=1)return n;

        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];

        }
        return dp[n];

        
    }
    int fib(int n) {

        return tabulation(n);
        
    }
};
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
    int fib(int n) {

        return spaceOptimized(n);
        
    }
};

// TC= O(N)  n-2 iterations 
// SC= O(1) Constant space because only 2 variables every time



