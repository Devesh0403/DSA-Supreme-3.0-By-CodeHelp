class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    
    {
        if(!root||root->left==NULL&&root->right==NULL)return 1;
        
        int sum=0;
        
        if(root->left){
            sum+=root->left->data;
            
        }
        if(root->right){
            sum+=root->right->data;
        }
        
        return root->data==sum&&isSumProperty(root->left)&&isSumProperty(root->right);
        
  
    }
};

// TC- O(N)
// SC - O(1)

