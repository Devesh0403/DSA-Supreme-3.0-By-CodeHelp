
class Solution {
public:
static bool comp(vector<int>&m1,vector<int>&m2){
        return m1[1]<m2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0; 
        
        
        sort(intervals.begin(),intervals.end(),comp);
        
        int ans=0;
        int limit=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if (intervals[i][0] < limit) {
                ans++;  // Overlapping interval, remove one
            } else {
                limit = intervals[i][1];  // Update limit to non-overlapping interval
            }
        }
        return ans;
        


        
    }
};