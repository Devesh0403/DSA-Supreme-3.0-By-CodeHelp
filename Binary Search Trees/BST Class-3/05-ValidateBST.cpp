class Solution {
public:
    bool check(TreeNode* root,long min,long max){
        if(!root)return true;

        if(root->val<=min || root->val>=max){
            return false;
        }

        return check(root->left,min,root->val)&&check(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        long min=LONG_MIN;
        long max=LONG_MAX;

        return check(root,min,max);
        
    }
};