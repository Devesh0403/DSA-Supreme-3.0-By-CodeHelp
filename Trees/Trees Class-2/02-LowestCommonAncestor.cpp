
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base cases
        if(root==NULL){
            return NULL;
        }

        else if(root->val==p->val){
            return p;

        }
        else if(root->val==q->val){
            return q;
        }
        
        // get left and right subtree answers
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);


        // check for the 4 cases

        //Case 1- Both values returned to the root are NULL
        if(leftAns==NULL&&rightAns==NULL){
            return NULL;
        }
        //Case 2- leftAns is NULL, rightAns isnt NULL
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        //Case 3- leftAns isnt NULL, rightAns is NULL
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        //Case 4- Both values arent NULL
        else{
            return root;
        }

        
    }
};

// Time complexity: O(N)
// Space complexity: O(N)