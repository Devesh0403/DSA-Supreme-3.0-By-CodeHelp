
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});

        unsigned long long maxWidth=0;


        while(!q.empty()){
            unsigned long long size=q.size();
            unsigned long long left=q.front().second;
            unsigned long long right=q.back().second;
            maxWidth=max(maxWidth,right-left+1);
            

            for(unsigned long long i=0;i<size;i++){
                TreeNode* front=q.front().first;
                unsigned long long index=q.front().second;
                q.pop();

                if(front->left){
                    q.push({front->left,index*2});
                }
                if(front->right){
                    q.push({front->right,index*2+1});
                }
            }


        }
        return maxWidth;
        
    }
};

// TC - O(N)
// SC - O(N)