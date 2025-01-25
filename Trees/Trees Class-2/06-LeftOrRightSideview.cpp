// METHOD 1 -  Using Depth 
class Solution {
public:
    void rightView(TreeNode* root,vector<int>&ans,int&depth){
        if(!root)return;

        if(ans.size()==depth)ans.push_back(root->val);

        depth++;
        rightView(root->right,ans,depth);
        rightView(root->left,ans,depth);
        depth--;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int depth=0;
        rightView(root,ans,depth);
        return ans;
    }
};

// TC - O(N) where n is the number of nodes in the tree.
// SC - O(h) where h is height of the tree


// METHOD 2 - Level Order Traversal


class Solution {
public:
   
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);

            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                level.push_back(front->val);

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            ans.push_back(level[level.size()-1]);

        }
        return ans;
        

        
    }
};


// TC - O(N) where n is the number of nodes in the tree.
// SC - O(N) 
