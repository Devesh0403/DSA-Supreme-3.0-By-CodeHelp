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
    int ans=0;
    void check(TreeNode* root,long long targetSum,int  &ans){
        if(root==NULL){
            return;
        }
        if(targetSum==root->val){
            ans++;
        }
        check(root->left,targetSum-root->val,ans);
        check(root->right,targetSum-root->val,ans);

        


    }
    int pathSum(TreeNode* root, long long targetSum) {
        
        if(root){

        check(root,targetSum,ans);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        }
        return ans;
        
    }
};