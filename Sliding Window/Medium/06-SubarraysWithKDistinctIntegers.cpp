class Solution {
public:
    int count(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int left=0,right=0;
        int cnt=0;

        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
        
    }
};
// TC - O(2*N)
// SC - O(1)