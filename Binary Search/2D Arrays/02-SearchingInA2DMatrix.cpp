// BRUTE FORCE - USING 2 LOOPS
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}
// TC- O(N^2)
// SC - O(1)


// BETTER APPROACH - USING BINARY SEARCH ON A ROW
class Solution {
public:
    bool check(vector<int>arr,int target){
        int start=0;
        int end=arr.size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target)return true;

            else if(target<arr[mid])end=mid-1;

            else start=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for (int row=0;row<matrix.size();row++){
            if(matrix[row][0]<=target&&target<=matrix[row][matrix[row].size()-1])return check(matrix[row],target);
        }

        return false;
        
        
    }
};
// TC - O(NLOGM)
// SC - O(1)


// OPTIMAL APPROACH- TREATING 2D MATRIX AS 1D MATRIX
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int rows=matrix.size();
        int columns=matrix[0].size();

        int n=rows*columns;
        int end=n-1;

        int mid=start+(end-start)/2;

        while(start<=end){
            int rowIndex=mid/columns;
            int colIndex=mid%columns;

            if(matrix[rowIndex][colIndex]==target){
                return true;
            }
            else if(target<matrix[rowIndex][colIndex]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;

        }
        return false;
        
        
    }
};

// TC - O(LOGN)
// SC - O(1)
