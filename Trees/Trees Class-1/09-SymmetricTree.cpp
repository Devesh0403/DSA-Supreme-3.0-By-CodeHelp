
class Solution {
public:
bool isMirror(TreeNode* p, TreeNode* q) {
    if(!p&&!q){
        return true;
    }
    else if(p&&q){
        return p->val==q->val&& isMirror(p->left,q->right)&&isMirror(p->right,q->left);
    }
    else return false;
        
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
        
    }
};