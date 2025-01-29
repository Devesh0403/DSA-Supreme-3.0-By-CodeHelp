// METHOD 1 - SAME AS BINARY TREE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)return NULL;

        else if(root->val==p->val){
            return p;

        }
        else if(root->val==q->val){
            return q;
        }

        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);


        if(leftAns&&rightAns){
            return root;
        }
        else if(leftAns==NULL&& rightAns!=NULL){
            return rightAns;
        }
        else if(leftAns!=NULL&& rightAns==NULL){
            return leftAns;
        }
        else return NULL;
    }
};
// TC- O(N)
// SC- O(N)


// METHOD 2 - RECURSIVE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)return NULL;

        if(root->val<p->val&&root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val>p->val&&root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;
        
    }
};
// TC- O(H)
// SC- O(H)



// METHOD 3 - ITERATIVE
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root)
            return NULL;

        while (root) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else
                break;
        }
        return root;
    }
};

// TC- O(H)
// SC- O(1)