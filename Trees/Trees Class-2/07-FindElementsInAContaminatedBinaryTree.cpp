
class FindElements {
    public:
        unordered_set<int>st;
    
        void helper(TreeNode*&root,int val){
            if(!root)return;
    
            root->val=val;
            st.insert(val);
            helper(root->left,2*val+1);
            helper(root->right,2*val+2);
    
    
        }
        FindElements(TreeNode* root) {
            if(root)helper(root,0);
            
        }
        
        bool find(int target) {
            return st.count(target);
            
        }
    };
