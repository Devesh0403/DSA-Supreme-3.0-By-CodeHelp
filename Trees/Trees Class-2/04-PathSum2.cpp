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
    void findAllPaths(TreeNode* root,int targetSum,int sum,vector<int>path,vector<vector<int>> &ans){
        if(root==NULL){
            return ;
        }
        sum+=root->val;
        path.push_back(root->val);

        if(root->left==NULL&& root->right==NULL){
            if(sum==targetSum){
                ans.push_back(path);
                
            }
            
        }

        findAllPaths(root->left,targetSum,sum,path,ans);
        findAllPaths(root->right,targetSum,sum,path,ans);

        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        vector<vector<int>>ans;
        int sum=0;
        findAllPaths(root,targetSum,sum,path,ans);
        return ans;
        
    }
};