// METHOD 1 - BRUTE FORCE
class Solution {
class Solution {
    public:
        int trap(vector<int>& height) {
    
            int ans=0;
            for(int i=1;i<height.size()-1;i++){
                int left=height[i];
                int right=height[i];
    
                for(int j=0;j<i;j++){
                    left=max(left,height[j]);
                }
                for(int j=i+1;j<height.size();j++){
                    right=max(right,height[j]);
                }
    
                ans+= (min(left, right) - height[i]);
            }
            return ans;
            
        }
    };


// METHOD 2 - BETTER APPROACH (USING A PREFIX AND SUFFIX ARRAY)
    class Solution {
        public:
            int trap(vector<int>& height) {
        
                int ans=0;
                int n=height.size();
                vector<int>left(n);
                vector<int>right(n);
        
                left[0]=height[0];
                right[n-1]=height[n-1];
        
                
                for(int i=1;i<n;i++){
                    left[i]=max(left[i-1],height[i]);
                }
                for(int i=n-2;i>=0;i--){
                    right[i]=max(right[i+1],height[i]);
                }
                
                for(int i=1;i<n-1;i++){
                    if(height[i]<min(left[i],right[i]))ans+=min(left[i],right[i])-height[i];
                }
                return ans;
            }
        };

        // TC - O(N)+ O(N) + O(N) [ prefix array + suffix array + computation]
        // SC - O(N) + O(N) + O(N) [ prefix array + suffix array + ans array]


// METHOD 3 - OPTIMAL APPROACH (USING 2 POINTERS ONLY)
        class Solution {
            public:
                int trap(vector<int>& arr) {
            
                    int left=1;
                    int right=arr.size()-2;
            
                    int lMax = arr[left - 1];
                    int rMax = arr[right + 1];
            
                    int ans=0;
            
                    while(left<=right){
                        if(rMax<=lMax){
                            ans+=max(0,rMax-arr[right]);
                            rMax=max(arr[right],rMax);
            
                            right--;
            
                        }
                        else {
                            ans+=max(0,lMax-arr[left]);
                            lMax=max(arr[left],lMax);
            
                            left++;
            
                        }
                    }
                    return ans;
                    
                }
            };
// TC - O(N)
// SC - O(1)