class Solution {
public:
    vector<vector<int>>ans;
    void check(vector<int>&candidates,int index,int target,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;

        }
        if(index==candidates.size()||target<0)return;

        temp.push_back(candidates[index]);
        check(candidates,index+1,target-candidates[index],temp);

        temp.pop_back();

        while(index+1<candidates.size()&&candidates[index]==candidates[index+1]){
            index++;
        }
        check(candidates,index+1,target,temp);




    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int>temp;
        check(candidates,0,target,temp);

        return ans;

        
    }
};

// TIME COMPLEXITY - O(2^N + NLOGN)
// SPACE COMPLEXITY - O(N+K)