class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            int value=nums[i];
            if(mp.find(target-value)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target-value]);
            }
            mp[value]=i;

        }
        return ans;
        
    }
};