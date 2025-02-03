class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int wt=0,t=0;
        for(int i=0;i<bt.size();i++){
            wt+=t;
            t+=bt[i];
        }
        return wt/bt.size();
        // code here
    }
};
// TC- O(NLOGN)+O(N)
// SC- O(1)