
class Solution {
public:
    int max_sum=INT_MIN;
    int maxPath(TreeNode* root){
        if(!root)return 0;

        int left=max(0,maxPath(root->left));
        int right=max(0,maxPath(root->right));

        max_sum=max(max_sum,root->val+left+right);

        return root->val+max(left,right);

    }
    int maxPathSum(TreeNode* root) {

        maxPath(root);
        return max_sum;
        
    }
};