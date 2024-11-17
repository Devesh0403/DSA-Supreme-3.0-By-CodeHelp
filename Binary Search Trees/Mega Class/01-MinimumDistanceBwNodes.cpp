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
    void solve(TreeNode* root,int &ans,TreeNode* &prev){
        if(root==NULL){
            return;
        }

        solve(root->left,ans,prev);

        if(prev){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;

        solve(root->right,ans,prev);


    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev=NULL;
        int ans=INT_MAX;
        solve(root,ans,prev);
        return ans;
        

        
    }
};