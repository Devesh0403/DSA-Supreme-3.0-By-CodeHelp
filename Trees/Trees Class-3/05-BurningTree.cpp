
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
    TreeNode* findStartNode(TreeNode* root, int start) {
        if (!root) return NULL;

        if (root->val == start) return root;

        TreeNode* leftSearch = findStartNode(root->left, start);
        if (leftSearch) return leftSearch;

        return findStartNode(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = NULL;
        mapToParent(root, mp);

        TreeNode* target = findStartNode(root, start);
        if (!target) return 0;

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        visited[target] = true;
        q.push(target);

        int time=0;

        while (!q.empty()) {
            int size = q.size();
        
            time++;
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
        return time-1;
        
    }
};