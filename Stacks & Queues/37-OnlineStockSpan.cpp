// LEETCODE SOLUTION
class StockSpanner {
    public:
        stack<pair<int,int>>st;
        StockSpanner() {
            
        }
        
        int next(int price) {
            int span=1;
    
            while(!st.empty()&&st.top().first<=price){
                span+=st.top().second; 
                // WE ADD THE SECOND AS SOME ELEMENTS ARE ALREADY POPPED, 
                // WHICH WERE SMALLER THAN THE TOP, AND SINCE OUR ELEMENT IS GREATER THAN THE TOP, 
                // IT IS GREATER THEN THOSE ELEMENTS AS WELL
                st.pop();
            }
            st.push({price,span});
            return span;
        }
    };

// OPTIMAL APPROACH - USING STACK
    public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st; // Stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            ans[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }

        return ans;
        // write code here
    }

    // TC- O(N)
    // SC- O(N)
