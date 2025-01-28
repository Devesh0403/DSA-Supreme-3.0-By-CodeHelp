
class Solution {
public:
    void mapToParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!root)
            return;

        if (root->left) {
            mp[root->left] = root;
            mapToParent(root->left, mp);
        }
        if (root->right) {
            mp[root->right] = root;
            mapToParent(root->right, mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = NULL;
        mapToParent(root, mp);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        visited[target] = true;
        q.push(target);

        int currLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if(currLevel==k){
                break;
            }
            currLevel++;
            for (int i = 0; i < size; i++) {

                TreeNode* front = q.front();
                q.pop();

                if (front->left && visited.find(front->left) == visited.end()) {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && visited.find(front->right) == visited.end()) {
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (mp[front] && visited.find(mp[front]) == visited.end()) {
                    q.push(mp[front]);
                    visited[mp[front]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};

// TC - O(N)
// SC - O(N) [QUEUE + VISITED MAP + PARENT MAP]