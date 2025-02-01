class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefixSumCount;
        int sum = 0, cnt = 0;

        prefixSumCount[0] = 1; 

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(prefixSumCount.find(sum-goal)!=prefixSumCount.end())cnt+=prefixSumCount[sum-goal];

            prefixSumCount[sum]++;


        }
        return cnt;
        
    }
};
// TC- O(N)
// SC- O(N) [MAP]