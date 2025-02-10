// METHOD -1 BRUTE FORCE (USING 4 LOOPS)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>>st;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    for(int l=k+1;l<nums.size();l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            vector<int>arr={nums[i],nums[j],nums[k],nums[l]};
                            sort(arr.begin(),arr.end());
                            st.insert(arr);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;

        
    }
};

// TC - O(N^4)
// SC - O(2*NUMBER OF PAIRS)

// METHOD - 2 (3 LOOPS AND A HASHSET)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                set<long long> hashset;
                for (int k = j + 1; k < nums.size(); k++) {
                    long long sum = nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum;
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k],
                                            (int)(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
// TC - O(N^3)+ O(LOGN)
// SC - O(2*NUMBER OF PAIRS) + O(N)

// OPTIMAL APPROACH

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }

                    else if (sum < target) {
                        k++;
                    } else
                        l--;
                }
            }
        }
        return ans;
    }
};

// TC - O(NLOGN)+ O(N^2 * N) = O(N^3)
// SC - O(NUMBER OF QUADS)
