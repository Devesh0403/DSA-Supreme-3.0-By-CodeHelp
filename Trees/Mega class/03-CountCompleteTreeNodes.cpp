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
    int findLeftHeight(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;

    }
    int findRightHeight(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
        
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh){
            return pow(2,lh)-1;
        }
        else{
            return 1+ countNodes(root->left)+countNodes(root->right);
        }


        
    }
};