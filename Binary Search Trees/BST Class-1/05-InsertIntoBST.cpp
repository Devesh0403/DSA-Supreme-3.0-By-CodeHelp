
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);

        if(root->val==val)return root;

        if(root->val<val){
            root->right=insertIntoBST(root->right,val);
        }
        else{
            root->left=insertIntoBST(root->left,val);
        }
        return root;
        
        
    }
};

// TC- O(h)
// SC - O(N)