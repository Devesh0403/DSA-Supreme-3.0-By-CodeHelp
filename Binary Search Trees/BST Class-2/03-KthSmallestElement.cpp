//SOLUTION-1 Using Inorder Sorted Array
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
            return;
            
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