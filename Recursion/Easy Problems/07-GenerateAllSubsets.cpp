class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>&ans,int index,vector<int>arr){
        if(index>=nums.size()){
            ans.push_back(arr);
            return;
        }

        helper(nums,ans,index+1,arr);
        arr.push_back(nums[index]);
        helper(nums,ans,index+1,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        vector<int>arr;
        helper(nums,ans, index,arr);
        return ans;
        
    }
};
// TC - O(2^N)
// SC - O(N)