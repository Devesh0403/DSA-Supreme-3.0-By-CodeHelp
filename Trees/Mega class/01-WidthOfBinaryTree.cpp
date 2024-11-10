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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        unsigned long long maxWidth=0;

        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});
        // q.push({NULL,-1});

        while(!q.empty()){
            unsigned long long length=q.size();
            //current level of nodes
            unsigned long long leftmostNodeIndex=q.front().second;
            unsigned long long rightmostNodeindex=q.back().second;

            maxWidth=max(maxWidth,rightmostNodeindex-leftmostNodeIndex+1);

            for(unsigned long long i=0;i<length;i++){
                auto front=q.front();
                q.pop();

                auto node=front.first;
                auto index=front.second;

                if(node->left){
                    q.push({node->left,index*2});
                }
                if(node->right){
                    q.push({node->right,index*2+1});
                }
            }
        }
        return maxWidth;


        
    }
};