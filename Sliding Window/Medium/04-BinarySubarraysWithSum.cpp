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

// 2 POINTER APPROACH
class Solution {
public:
int check(vector<int>& nums,int goal){
        if(goal<0)return 0;

        int left=0;
        int right=0;
        int cnt=0;
        int sum=0;

        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            if(sum<=goal)cnt+=(right-left+1);
            right++;


        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return check(nums,goal)-check(nums,goal-1);
        
        
    }
};

// TC - O(2*N)
// SC - O(1)