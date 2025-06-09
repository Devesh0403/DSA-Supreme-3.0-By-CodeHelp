// SOLUTION 1- USING 2 LOOPS [O(N^2)]
class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            for(int i=0;i<nums.size();i++){
                int lsum=0;
                int rsum=0;
                for(int j=0;j<i;j++){
                    lsum+=nums[j];
                }
                for(int j=i+1;j<nums.size();j++){
                    rsum+=nums[j];
    
                }
                if(lsum==rsum)return i;
            }
            return -1;
        }
    };

// TC - O(N^2)
// SC - O(1)

// SOLUTION 2 - PREFIX SUM APPROACH

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            vector<int>lsum(nums.size());
            vector<int>rsum(nums.size());
    
            for(int i=1;i<nums.size();i++){
                lsum[i]=lsum[i-1]+nums[i-1];
            }
            for(int i=nums.size()-2;i>=0;i--){
                rsum[i]=rsum[i+1]+nums[i+1];
            }
    
            for(int a=0;a<nums.size();a++){
                if(lsum[a]==rsum[a]){
                    return a;
                }
            }
            return -1;
            
        }
    };

// TC - O(N)
// SC - O(2*N)