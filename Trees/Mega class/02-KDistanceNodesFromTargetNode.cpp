/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapToParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        if(root==NULL){
            return;
        }
        if(root->left){
            mp[root->left]=root;
            mapToParent(root->left,mp);
        }
        if(root->right){
            mp[root->right]=root;
            mapToParent(root->right,mp);
        }
        }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root]=NULL;
        mapToParent(root,mp);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;

        int currLevel=0;

        while(!q.empty()){
            int size=q.size();
            if(currLevel==k){
                break;
            }
            currLevel++;
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                if(front->left && visited.find(front->left)==visited.end()){
                    //left child isnt visited
                    q.push(front->left);
                    visited[front->left]=true;
                    
                }
                if(front->right && visited.find(front->right)==visited.end()){
                    //right child isnt visited
                    q.push(front->right);
                    visited[front->right]=true;
                    
                }
                auto parent=mp[front];
                if(mp[front] && visited.find(parent)==visited.end()){
                    //parent isnt visited
                    q.push(parent);
                    visited[parent]=true;
                    
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