
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return true;
        }
        else if(p&&q){
            return (p->val==q->val)
            && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
             
        }
        else{
            return false;
        }   
    }
};
// TC - O(M + N)
// SC - O(1)