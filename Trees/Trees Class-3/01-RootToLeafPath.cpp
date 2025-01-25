
class Solution {
  public:
    vector<vector<int>>ans;
    void traversal(Node* root,vector<int>&path){
        if(!root)return;
        
        path.push_back(root->data);

        // If this is a leaf node, add the current path to the result
        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            // Recursively traverse the left and right subtrees
            traversal(root->left, path);
            traversal(root->right, path);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        if(!root)return ans;
        vector<int>path;
        
        traversal(root,path);
        return ans;
        // code here
    }
};
