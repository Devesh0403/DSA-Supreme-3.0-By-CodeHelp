// METHOD 1 - BRUTE FORCE (USING 3 LOOPS)
vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>ans;
        set<vector<int>> st;
        int n=nums.size();

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                for (int k=j+1;k<n;k++) {
                    if (nums[i]+nums[j]+nums[k]==0){

                        vector<int>arr={nums[i],nums[j],nums[k]};
                        sort(arr.begin(),arr.end());
                        st.insert(arr);

                     
                    }
                }
            }
        }

        for(auto arr:st){
            ans.push_back(arr);
        }

        return ans;
    }
// TC - O(N^3 * LOGX)
// SC - O(2 * no. of the unique triplets)

// METHOD 2- BETTER APPROACH USING 2 LOOPS AND HASH SET

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// TC - O(N^2 * LOGX)
// SC - O(2 * no. of the unique triplets)

// OPTIMAL APPROACH

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;

                else {
                    vector<int> arr = {nums[i], nums[j], nums[k]};
                    ans.push_back(arr);
                    j++;
                    k--;
                    // skip the duplicates:
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};
// Time Complexity: O(NlogN)+O(N2), 
// Space Complexity: O(no. of quadruplets),