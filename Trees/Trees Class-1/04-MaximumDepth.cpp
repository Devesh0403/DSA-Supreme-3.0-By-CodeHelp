
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int leftAns=maxDepth(root->left);
        int rightAns=maxDepth(root->right);

        int maxHeight=max(leftAns,rightAns);
        int totalHeight=maxHeight+1;
        return totalHeight;
        
    }
};