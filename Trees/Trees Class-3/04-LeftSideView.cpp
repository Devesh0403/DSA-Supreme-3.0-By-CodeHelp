
class Solution {
  public:
    void left(Node * root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        left(root->left,ans,level+1);
        left(root->right,ans,level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        int level=0;
        left(root,ans,level);
        return ans;
    }
};



