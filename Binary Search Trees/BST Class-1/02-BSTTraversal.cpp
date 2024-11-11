void preorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}

int main() {
    Node* root=createTree();
    // levelOrderTraversal(root);
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    
    
    return 0;
    
    
}