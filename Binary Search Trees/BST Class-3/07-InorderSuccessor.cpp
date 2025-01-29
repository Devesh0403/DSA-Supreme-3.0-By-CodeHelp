// METHOD - 1 Using Inorder Array 

void inorder(Node* root,vector<int>&arr){
        if(!root)return;
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    int inOrderSuccessor(Node *root, Node *x) {
        
        if(!root)return -1;
        // int ans=-1;
        vector<int>arr;
        inorder(root,arr);
        
        if(arr[arr.size()-1]==x->data)return -1;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x->data) return arr[i+1];
            
        }
        
        
        // Your code here
}
// TC - O(N)
// SC - O(N)

// METHOD -2 USING BINARY SEARCH
int inOrderSuccessor(Node *root, Node *x) {
        
        Node* ans=NULL;
       Node* curr=root;
       while(curr){
           if(curr->data>x->data){
               ans=curr;
               curr=curr->left;
           }
           else if(curr->data<=x->data){
               curr=curr->right;
           }
       }
       return ans?ans->data:-1;
        // Your code here
    }
// TC- O(H)
// SC- O(1)