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
    vector<int>arr;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* buildTree(vector<int>&arr,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;

        TreeNode* root=new TreeNode(arr[mid]);
        root->left=buildTree(arr,start,mid-1);
        root->right=buildTree(arr,mid+1,end);

        return root;


    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        

        return buildTree(arr,0,arr.size()-1);

        




        
    }
};