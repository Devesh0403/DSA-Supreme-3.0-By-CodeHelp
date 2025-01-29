class Solution {
public:
    pair<TreeNode*,int> helper(TreeNode* root){
        if(!root)return {NULL,0};

        auto [lcaLeft,lDepth]=helper(root->left);
        auto [rcaLeft,rDepth]=helper(root->right);

        if(lDepth>rDepth)return {lcaLeft,1+lDepth};
        if(rDepth>lDepth)return {rcaLeft,1+rDepth};

        return {root,1+lDepth};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
        
    }
};