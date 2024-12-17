/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        if (start > end)
            return {NULL};
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            vector < TreeNode*> leftBST = solve(start, i - 1);
            vector < TreeNode*> rightBST = solve(i + 1, end);

            for (TreeNode* leftRoot : leftBST) {
                for (TreeNode* rightRoot : rightBST) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    map<pair<int,int>,vector<TreeNode*>>mp;
    vector<TreeNode*> memoization(int start, int end) {
        if (start > end)
            return  {NULL};
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            return mp[{start,end}]={root};
        }

        if(mp.find({start,end})!=mp.end())return mp[{start,end}];

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            vector < TreeNode*> leftBST = memoization(start, i - 1);
            vector < TreeNode*> rightBST = memoization(i + 1, end);

            for (TreeNode* leftRoot : leftBST) {
                for (TreeNode* rightRoot : rightBST) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    ans.push_back(root);
                }
            }
        }
        return mp[{start,end}]= ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};