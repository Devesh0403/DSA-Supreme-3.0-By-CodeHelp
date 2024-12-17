int recursive(vector<int>&nums,int index,int last){
        if(index==nums.size())return 0;

        int exc=0+recursive(nums,index+1,last);

        int inc=0;
        if(last==-1||nums[index]>nums[last]){
            inc=1+recursive(nums,index+1,index);
        }

        return max(inc,exc);


    }
    int memoization(int lastIndex, vector<int>& nums, int i,
              vector<vector<int>>& dp) {
        // base case
        if (i >= nums.size())
            return 0;

        int curr = nums[i];
        int inc = 0;

        // Step-2 : check if the solution is already present or not
        if (dp[lastIndex + 1][i] != -1)
            return dp[lastIndex + 1][i];

        // Step-3 :if lastindex == -1 i.e. it is the first element OR the
        // element is greater than last then include it in the subsequence
        if (lastIndex == -1 || curr > nums[lastIndex]) {
            inc = 1 + memoization(i, nums, i + 1, dp);
        }
        // in every case exclude it as well
        int exc = 0 + memoization(lastIndex, nums, i + 1, dp);

        // Step-4 :return max of inc & exc and store in dp array
        return dp[lastIndex + 1][i] = max(inc, exc);
    }
