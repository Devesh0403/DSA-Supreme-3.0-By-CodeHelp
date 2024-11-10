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
    int check(TreeNode* root, int& cameras){
        if(root==NULL){
            return 1;

        }
        int left=check(root->left,cameras);
        int right=check(root->right,cameras);

        if(left==0||right==0){
            cameras++;
            return 2;
        }
        else if(left==2||right==2){
            return 1;
        }
        return 0;

    }
    int minCameraCover(TreeNode* root) {
        
        
        int cameras=0;
        int rootState=check(root,cameras);
        if(rootState==0){
            cameras++;
        }
        return cameras;
        
        
    }
};