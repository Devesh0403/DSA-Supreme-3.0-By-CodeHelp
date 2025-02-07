// METHOD 1 - BRUTE FORCE (2 LOOPS) 
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxi=0;
        int row=-1;
        
        for(int i=0;i<arr.size();i++){
            int count=0;
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1)count++;
            }
            if (count>maxi){
                maxi=count;
                row=i;
            }
        }
        return row;
        // code here
    }
};
// TC - O(N^2 )
// SC - O(1)

// METHOD 2 - BINARY SEARCH
class Solution {
  public:
    int findOnes(vector<int>&arr){
        int start=0;
        int end=arr.size()-1;
        int ans = arr.size();
        
        while(start<=end){
             int mid=(start+end)/2;
             if(arr[mid]==1){
                 ans=mid;
                 end=mid-1;
             }
             else{
                 start=mid+1;
             }
            
        }
        return arr.size()-ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxi=0;
        int maxRow=-1;
        
        for(int row=0;row<arr.size();row++){
            int ones=findOnes(arr[row]);
            if(ones>maxi){
                maxi=ones;
                maxRow=row;
            }
        }
        return maxRow;
        // code here
    }
};
// TC - O(N* LOGN )
// SC - O(1)


// METHOD 3 - OPTIMAL APPROACH
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int row = -1, col = m - 1;

        for (int i = 0; i < n; i++) {
            while (col >= 0 && arr[i][col] == 1) {
                row = i;
                col--;  // Move left
            }
        }
        return row;
        // code here
    }
};
// TC - O(N + M )
// SC - O(1)