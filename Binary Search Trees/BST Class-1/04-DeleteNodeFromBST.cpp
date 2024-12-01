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
int getMin(TreeNode* root){
    if(root==NULL){
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->val;
}
    int getMax(TreeNode* root){
    if(root==NULL){
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL){
            return NULL;
        }
        // Case 1- When the root ki val is same as the key. 
        // Then check for children- 4 CASES
        if(root->val==key){
            //case 1- No child
            if(root->left==NULL&& root->right==NULL){
                delete root;
                return NULL;
            }

            //case 2- both child
            if(root->left!=NULL&&root->right!=NULL){
                int minVal=getMin(root->right);

                root->val=minVal;
                root->right=deleteNode(root->right,minVal);
                return root;
            }

            //case 3- Left child only
            else if(root->left!=NULL&& root->right==NULL){
                TreeNode* leftChild=root->left;
                root->left=NULL;
                delete root;
                return leftChild;

            }

            //case 4- right child only
            else{
                TreeNode * rightChild=root->right;
                root->right=NULL;
                delete root;
                return rightChild;
            }



        }
        else{
            if(root->val<key){
                root->right=deleteNode(root->right,key);
            }
            else{
                root->left=deleteNode(root->left,key);
            }

        }
        return root;
        
    }
};