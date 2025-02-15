//SOLUTION-1 Using Inorder Sorted Array
class Solution {
public:
    void check(TreeNode* root, vector<int>&inorder){
        if(!root)return;

        check(root->left,inorder);
        inorder.push_back(root->val);
        check(root->right,inorder);

    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans=NULL;
        int count=0;
        vector<int>inorder;

        check(root,inorder);
        return inorder[k-1];
        
    }
};
// TC- O(N)
// SC- O(N) [ARRAY]













// SOLUTION-2 Using Recursion
class Solution {
public:
    void inorder(TreeNode* root,int &count,int k,TreeNode* &ans){
        if(root==NULL){
            return;
        }
        //Left part
        inorder(root->left,count,k,ans);

        //Current Node
        count++;
        if(count==k){
            ans=root;
            
        }

        //Right part
        inorder(root->right,count,k,ans);


    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        TreeNode* ans=NULL;
        int count=0;
        inorder(root,count,k,ans);
        return ans->val;


        
    }
};