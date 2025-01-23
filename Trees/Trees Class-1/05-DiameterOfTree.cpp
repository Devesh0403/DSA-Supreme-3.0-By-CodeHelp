class Solution {
public:
    void diameter(TreeNode* root,int& diameter){
        if(root==NULL)return 0;

        int lh=diameter(root,diameter);
        int rh=diameter(root,diameter);

        diameter=max(diameter,rh+lh);
        
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int diameter=0;
        diameter(root,diameter);
        return diameter;
        
    }
};