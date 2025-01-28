// METHOD 1 - Recursive Way
class Solution {
public:
    void count(TreeNode* root,int &ans){
        if(!root)return;
        ans++;
        count(root->left,ans);
        count(root->right,ans);

    }
    int countNodes(TreeNode* root) {
        int ans=0;
        count(root,ans);
        return ans;
    }
};

// TC - O(N)
// SC - O(N) [ RECURSIVE STACK]



// METHOD 2 - Left and Right Heights
class Solution {
public:
int findHeightLeft(TreeNode* node) {
        int height = 0;
        // Traverse left child until
        // reaching the leftmost leaf
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Function to find the right height of a tree
    int findHeightRight(TreeNode* node) {
        int height = 0;
        // Traverse right child until
        // reaching the rightmost leaf
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {

        if (!root)
            return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh)
            return pow(2, lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Time Complexity: O(log N * log N)
// Space Complexity : O(H) ~ O(N)