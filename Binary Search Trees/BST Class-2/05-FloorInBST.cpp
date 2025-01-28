// USING BINARY SEARCH
int floor(Node* root, int input) {
    int floor=-1;
    
    while(root){
        if(root->data==input){
            return input;
        }
        else if(root->data<input){
            floor=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
        // Code here
}
// TC - O(logN)
// SC - O(1)
 