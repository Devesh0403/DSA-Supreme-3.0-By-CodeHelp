class Solution {
    public:
        vector<int>findPSE(vector<int>& heights){
            vector<int>pse(heights.size(),-1);
            stack<int>st;
    
            for(int i=0;i<heights.size();i++){
                while(!st.empty()&&heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(!st.empty())pse[i]=st.top();
                st.push(i);
            }
            return pse;
    
        }
        vector<int>findNSE(vector<int>& heights){
            vector<int>nse(heights.size(),heights.size());
            stack<int>st;
    
            for(int i=heights.size()-1;i>=0;i--){
                while(!st.empty()&&heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(!st.empty())nse[i]=st.top();
                st.push(i);
            }
            return nse;
    
        }
        int largestRectangleArea(vector<int>& heights) {
            
            vector<int>nse=findNSE(heights);
            vector<int>pse=findPSE(heights);
            int maxi=0;
    
            for(int i=0;i<heights.size();i++){
                int area=heights[i]*(nse[i]-pse[i]-1);
                maxi=max(area,maxi);
            }
            return maxi;
    
    
    
            
            
        }
    };