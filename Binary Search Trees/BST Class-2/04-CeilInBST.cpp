// USING BINARY SEARCH

int findCeil(Node* root, int input) {
    int ceil=-1;
    
    while(root){
        if(root->data==input){
            return input;
        }
        else if(root->data<input){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;

}

// TC - O(logN)
// SC - O(1)