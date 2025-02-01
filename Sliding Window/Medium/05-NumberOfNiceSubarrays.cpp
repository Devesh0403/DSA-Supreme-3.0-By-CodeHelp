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