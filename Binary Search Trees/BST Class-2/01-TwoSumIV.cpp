/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void storeSorted(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        storeSorted(root->left,arr);
        arr.push_back(root->val);
        storeSorted(root->right,arr);

        return;

    }
    bool checkSum(int target,vector<int>arr){
        int start=0;
        int end=arr.size()-1;

        while(start<end){
            if(arr[start]+arr[end]==target){
                return true;
            }
            else if(arr[start]+arr[end]<target){
                start++;
            }
            else{
                end--;
            }
        }
        return false;

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        storeSorted(root,arr);
        return checkSum(k,arr);
        
    }
};