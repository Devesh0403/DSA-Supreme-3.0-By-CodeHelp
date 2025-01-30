class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0||s.size()==1)
            return s.size();

        int maxans = 0;
        unordered_set<char>st;

        int l=0,r=0;

        while(r<s.size()){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;

            }
            st.insert(s[r]);
            maxans=max(maxans,r-l+1);
            r++;
        }
        return maxans;

    }
};
// TC- O(N)
// SC- O(N)