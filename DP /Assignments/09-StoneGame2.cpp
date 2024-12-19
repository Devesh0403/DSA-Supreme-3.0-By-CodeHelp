class Solution {
public:
    int recursive(vector<int>&piles,int index,int m,bool isAlice){
        if(index==piles.size())return 0;

        int ans=isAlice?INT_MIN:INT_MAX;

        int total=0;
        for(int x=1;x<=2*m;x++){
            if(index+x-1>=piles.size())break;

            total+=piles[index+x-1];
            if(isAlice){
                ans=max(ans,total+recursive(piles,index+x,max(x,m),!isAlice));
            }
            else{
                ans=min(ans,recursive(piles,index+x,max(x,m),!isAlice));

            }
        }
        return ans;


    }
    int memoization(vector<int>&piles,int index,int m,bool isAlice,vector<vector<vector<int>>>&dp){
        if(index==piles.size())return 0;

        if(dp[index][m][isAlice]!=-1)return dp[index][m][isAlice];

        int ans=isAlice?INT_MIN:INT_MAX;

        int total=0;
        for(int x=1;x<=2*m;x++){
            if(index+x-1>=piles.size())break;

            total+=piles[index+x-1];
            if(isAlice){
                ans=max(ans,total+memoization(piles,index+x,max(x,m),!isAlice,dp));
            }
            else{
                ans=min(ans,memoization(piles,index+x,max(x,m),!isAlice,dp));

            }
        }
        return dp[index][m][isAlice]= ans;


    }
    int stoneGameII(vector<int>& piles) {

        return recursive(piles,0,1,1);
        
    }
};