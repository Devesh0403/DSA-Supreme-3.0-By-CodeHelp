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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;


        TreeNode* curr=root;
        while(curr){
            //left is null, visit and go to right
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            //left node isnt null
            else{
                TreeNode* pred=curr->left;
                while(pred->right!=curr && pred->right){
                    pred=pred->right;
                }

                //if right is null, go left after pointing the predecessor
                if(pred->right==NULL){

                pred->right=curr;
                curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        
        return ans;


        
    }
};