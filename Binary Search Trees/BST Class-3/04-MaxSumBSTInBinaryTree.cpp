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
    class Info{
        public:
        int min;
        int max;
        bool isBST;
        int sum;
    };
    int sum=0;

    Info solve(TreeNode* root){
        if(root==NULL){
            Info temp;
            temp.max=INT_MIN;
            temp.min=INT_MAX;
            temp.isBST=true;
            temp.sum=0;
            sum=max(sum,temp.sum);
            return temp;

        }
       
        Info leftAns=solve(root->left);
        Info rightAns=solve(root->right);
        

        Info currentAns;
        currentAns.min=min(root->val,min(leftAns.min,rightAns.min));
        currentAns.max=max(root->val,max(leftAns.max,rightAns.max));
        currentAns.sum=leftAns.sum+rightAns.sum+root->val;
        currentAns.isBST=root->val>leftAns.max&&root->val<rightAns.min&&leftAns.isBST&&rightAns.isBST;

        if(currentAns.isBST){
            sum=max(sum,currentAns.sum);
        }

        return currentAns;

    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return sum;
        
    }
};