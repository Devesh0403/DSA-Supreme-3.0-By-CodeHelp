class Solution {
public:
    void helper(vector<int>curr,vector<vector<int>>&ans,int k,int n,int start){
        if(k==0&&n==0){
            ans.push_back(curr);
            return;
        }

        if(k<0||n<0)return;

        for(int i=start;i<=9;i++){
            curr.push_back(i);
            helper(curr,ans,k-1,n-i,i+1);
            curr.pop_back();
            

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>ans;
        helper(curr,ans,k,n,1);
        return ans;
        
        
    }
};