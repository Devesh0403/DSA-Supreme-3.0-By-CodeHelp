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
    void rightView(TreeNode* root,vector<int>& ans,int &depth){
        if(root==NULL){
            return;
        }
        if(ans.size()==depth){
            ans.push_back(root->val);
        }
        depth++;
        rightView(root->right,ans,depth);
        rightView(root->left,ans,depth);
        depth--;


    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        int depth=0;
        rightView(root,ans,depth);
        return ans;
        
    }
};