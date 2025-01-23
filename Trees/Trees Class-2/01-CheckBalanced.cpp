
class Solution {
public:
    int getHeight(TreeNode* root){
        if(!root)return 0;

        int lh=getHeight(root->left);
        int rh=getHeight(root->right);

        return max(lh,rh)+1;

    }
    bool isBalanced(TreeNode* root) {

        if(!root)return true;

        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right)) {
            return true;
        }

        return false;


        
    }
};