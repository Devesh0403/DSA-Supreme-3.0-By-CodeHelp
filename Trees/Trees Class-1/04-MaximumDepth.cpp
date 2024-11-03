using namespace std;
#include <iostream>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int leftAns=maxDepth(root->left);
        int rightAns=maxDepth(root->right);

        int maxHeight=max(leftAns,rightAns);
        int totalHeight=maxHeight+1;
        return totalHeight;
        
    }
};