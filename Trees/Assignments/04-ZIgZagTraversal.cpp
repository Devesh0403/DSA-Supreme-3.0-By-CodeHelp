/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void zigzag(TreeNode* root, vector<vector<int>>&ans,bool &reverse) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int width=q.size();
            vector<int>level(width);

            for(int i=0;i<width;i++){
                 TreeNode* front=q.front();
                 q.pop();

                 int index=reverse? width-i-1:i;
                 level[index]=front->val;
                 

                 if(front->left){
                    q.push(front->left);
                 }
                 if(front->right){
                    q.push(front->right);
                 }
                 

            }
            reverse=!reverse;
                 ans.push_back(level);
            

        }


        
        }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool reverse=false;
        zigzag(root, ans,reverse);
        return ans;
    }
};