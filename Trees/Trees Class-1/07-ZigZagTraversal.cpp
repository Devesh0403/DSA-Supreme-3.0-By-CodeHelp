
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>ans;

        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool reverse=false;

        while (!q.empty()) {
            int size = q.size();
            vector<int>level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                int index=reverse?size-i-1:i;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                level[index]=front->val;
                
            }
            ans.push_back(level);
            reverse=!reverse;


        }
        return ans;
    }
};