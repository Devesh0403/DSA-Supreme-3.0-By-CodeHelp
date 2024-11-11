
class Solution {
public:
    void inorderSort(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        inorderSort(root->left,arr);
        arr.push_back(root->val);
        inorderSort(root->right,arr);
        return;

    }
    void replace(TreeNode* root,unordered_map<int,int>mp){
        if(root==NULL){
            return;
        }
        root->val=mp[root->val];
        replace(root->left,mp);
        replace(root->right,mp);

    }

    TreeNode* bstToGst(TreeNode* root) {
        unordered_map<int,int>mp;
        vector<int>arr;
        inorderSort(root,arr);

        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
            }
            mp[arr[i]]=sum;
        }

        replace(root,mp);
        return root;


        
    }
};

