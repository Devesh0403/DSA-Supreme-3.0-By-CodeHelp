int totalElements(vector<int> &arr) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        
        int left=0;
        int right=0;
        
        int maxLen=0;
        
        while(right<arr.size()){
            while(st.size()>2){
                mp[arr[left]]--;
                if(mp[arr[left]]==0)st.remove(arr[left]);
                left++;
            }
            right++;
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
        // code here
    }
// TC- O(N)
// SC- O(N) [MAP+SET]