class Solution {
public:
void helper(vector<int>& nums,vector<vector<int>>&ans,int index,int target,vector<int>arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(index>=nums.size()||target<0){
            return;
        }
        arr.push_back(nums[index]);
        helper(nums,ans,index,target-nums[index],arr);
        arr.pop_back();
        helper(nums,ans,index+1,target,arr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int index=0;
        vector<int>arr;
        helper(nums,ans, index,target,arr);
        return ans;
        

        
    }
};