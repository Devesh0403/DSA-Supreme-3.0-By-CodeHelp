// BRUTE FORCE - USING 2 LOOPS
class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int ans = 0;
            int mod=1e9+7;
    
            for (int i = 0; i < arr.size(); i++) {
                int mini = arr[i];
                for (int j = i; j < arr.size(); j++) {
                    mini = min(mini, arr[j]);
    
                    ans += mini;
                    ans=ans%mod;
                }
            }
            return ans%mod;
        }
    };

    // TC- O(N^2)
    // SC- O(1)
        

// OPTIMAL APPROACH - USING PREVIOUS & NEXT SMALLER ELEMENT LOGIC

    class Solution {
        public:
            vector<int> nse(vector<int>& arr) {
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
        
            vector<int> pse(vector<int>& arr) {
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
        
            int sumSubarrayMins(vector<int>& arr) {
                vector<int> pseArray = pse(arr);
                vector<int> nseArray = nse(arr);  
        
                int mod = 1e9 + 7;
                long long ans = 0;
        
                for (int i = 0; i < arr.size(); i++) {
                    long long left = i - pseArray[i];
                    long long right = nseArray[i] - i;
        
                    ans = (ans + (left * right % mod) * arr[i] % mod) % mod;
                }
                return ans;
            }
        };

        // TC- O(N)+O(N)+O(N)
        // SC- O(2*N)
        