// BRUTE FORCE - USING 2 LOOPS
vector<int> nextLargerElement(vector<int>& arr) {
        vector<int>ans(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>arr[i]){
                    ans[i]=arr[j];
                    break;
                }
            }
        }
        return ans;
        // code here
    }
// TC - O(N^2)
// SC - O(N)  [ FOR ANSWER ARRAY ]


// OPTIMAL APPROACH - USING STACK
vector<int> nextLargerElement(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            
            st.push(arr[i]);
        }
        return ans;
        // code here
    }
// TC - O(N)
// SC - O(N) + O(N)  [ FOR ANSWER ARRAY & STACK]


