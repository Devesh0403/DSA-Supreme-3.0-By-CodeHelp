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
    TreeNode* construct(vector<int>&preorder,int min,int max,int &i){
        if(i>=preorder.size()){
            return NULL;
        }
        TreeNode* root=NULL;
        if(preorder[i]>min&&preorder[i]<max){
            root=new TreeNode(preorder[i++]);
            root->left=construct(preorder,min,root->val,i);
            root->right=construct(preorder,root->val,max,i);

        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN;
        int max=INT_MAX;

        int i=0;
        TreeNode* root=construct(preorder,min,max,i);
        return root;
        
    }
};