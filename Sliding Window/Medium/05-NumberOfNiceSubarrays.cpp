// BRUTE FORCE - USING 2 LOOPS
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int n=nums.size();

        // traverse for all
        // possible subarrays
        for (int i = 0; i < n; i++) {
            int odd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2)
                    odd++;

                // if count of odd numbers in
                // subarray is m
                if (odd == k)
                    count++;
            }
        }
        return count;
    }
};

// TC- O(N^2)
// SC- O(1)

// METHOD 2- SAME AS NUMBER OF BINARY SUBARRAYS WITH SUM K

class Solution {
public:
int check(vector<int>& nums,int goal){
        if(goal<0)return 0;

        int left=0;
        int right=0;
        int cnt=0;
        int sum=0;

        while(right<nums.size()){
            // CONSIDER ODD AS 1 AND EVEN AS 0
            sum+=nums[right]%2;
            while(sum>goal){
                sum-=nums[left]%2;
                left++;
            }
            if(sum<=goal)cnt+=(right-left+1);
            right++;


        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return check(nums,goal)-check(nums,goal-1);
        
        
    }
};
// TC - O(2*N)
// SC - O(1)