
// METHOD 1 BRUTE FORCE
class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            long long ans=0;
    
            for(int i=0;i<nums.size();i++){
                int mini=nums[i];
                int maxi=nums[i];
                for(int j=i;j<nums.size();j++){
                    if(nums[j]>maxi)maxi=nums[j];
                    if(nums[j]<mini)mini=nums[j];
    
                    ans+=maxi-mini;
    
                }
                
            }
            return ans;
            
        }
    };

    // TC - O(N^2)
    // SC - O(1)


// METHOD 2 OPTIMAL APPROACH
    class Solution {
        public:
        vector<int> findNse(vector<int>& arr) {
                        stack<int> st;
                        vector<int> ans(arr.size());
                
                        for (int i = arr.size() - 1; i >= 0; i--) {
                            while (!st.empty() && arr[st.top()] >= arr[i]) 
                                st.pop();
                
                            ans[i] = st.empty() ? arr.size() : st.top();
                            st.push(i);
                        }
                        return ans;
                    }
                
                    vector<int> findPse(vector<int>& arr) {
                        stack<int> st;
                        vector<int> ans(arr.size());
                
                        for (int i = 0; i < arr.size(); i++) {
                            while (!st.empty() && arr[st.top()] > arr[i]) 
                                st.pop();
                
                            ans[i] = st.empty() ? -1 : st.top();
                            st.push(i);
                        }
                        return ans;
                    }
            vector<int> findNle(vector<int>& arr) {
                        stack<int> st;
                        vector<int> ans(arr.size());
                
                        for (int i = arr.size() - 1; i >= 0; i--) {
                            while (!st.empty() && arr[st.top()] <= arr[i]) 
                                st.pop();
                
                            ans[i] = st.empty() ? arr.size() : st.top();
                            st.push(i);
                        }
                        return ans;
                    }
                
                    vector<int> findPle(vector<int>& arr) {
                        stack<int> st;
                        vector<int> ans(arr.size());
                
                        for (int i = 0; i < arr.size(); i++) {
                            while (!st.empty() && arr[st.top()] < arr[i]) 
                                st.pop();
                
                            ans[i] = st.empty() ? -1 : st.top();
                            st.push(i);
                        }
                        return ans;
                    }
            long long subArrayRanges(vector<int>& arr) {
                long long largeSum=0;
                long long smallSum=0;
                
                vector<int>ple=findPle(arr);
                vector<int>nle=findNle(arr);
                vector<int>pse=findPse(arr);
                vector<int>nse=findNse(arr);
        
                for(int i=0;i<arr.size();i++){
                    
                    long long leftL=i-ple[i];
                    long long rightL=nle[i]-i;
                    
                    long long leftS=i-pse[i];
                    long long rightS=nse[i]-i;
                    
                    largeSum=largeSum+(rightL*leftL*arr[i]);
                    smallSum=smallSum+(rightS*leftS*arr[i]);
                    
                    
                }
                return largeSum-smallSum;
            }
        };

        // TC - O(N)
        // SC - O(N)