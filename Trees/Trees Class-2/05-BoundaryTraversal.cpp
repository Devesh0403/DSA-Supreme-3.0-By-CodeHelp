
class Solution {
  public:
    void leftBoundary(Node* root,vector<int>&ans){
        if(!root)return;
        if(!root->left&&!root->right)return;
        
        ans.push_back(root->data);
        
        if(root->left)leftBoundary(root->left,ans);
        else leftBoundary(root->right,ans);
    }
    void rightBoundary(Node* root,vector<int>&ans){
        if(!root)return;
        if(!root->left&&!root->right)return;
        
        if(root->right)rightBoundary(root->right,ans);
        else rightBoundary(root->left,ans);
        
        ans.push_back(root->data);
    }
    void leafBoundary(Node* root,vector<int>&ans){
        if(!root)return;
        if(!root->left&&!root->right)ans.push_back(root->data);
        
        leafBoundary(root->left,ans);
        leafBoundary(root->right,ans);

    }
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int>ans;
        if(!root)return ans;
        
        if(root->left==NULL&& root->right==NULL){
            return {root->data};
        }
        // Case -1 Root Node
        ans.push_back(root->data);
        
        // Case -2 Left Boundary
        leftBoundary(root->left,ans);
        
        // Case -3 Leaf Nodes
        leafBoundary(root,ans);
        
        // Case -4 Right Boundary
        rightBoundary(root->right,ans);
    
        return ans;
        
    }
};