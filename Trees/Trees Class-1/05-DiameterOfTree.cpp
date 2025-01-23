
class Solution {
public:
    int diameterHelper(TreeNode* root,int &diameter){
        if(root==NULL)return 0;

        int lh=diameterHelper(root->left,diameter);
        int rh=diameterHelper(root->right,diameter);

        diameter=max(diameter,rh+lh);
        
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int diameter=0;
        diameterHelper(root,diameter);
        return diameter;
        
    }
};