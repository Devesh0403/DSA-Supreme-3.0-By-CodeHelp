class Solution{
    public:
    bool isValidBst(Node *root, int minValue, int maxValue) {
    if (!root)
        return true;
    if (root->data >= maxValue || root->data <= minValue)
        return false;
    return isValidBst(root->left, minValue, root->data) && 
           isValidBst(root->right, root->data, maxValue);
}

    int size(Node *root) {
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

    int largestBst(Node *root)
    {
        if(!root)return 0;
        
        if(isValidBst(root, INT_MIN, INT_MAX)){
            return size(root);
        }
        return max(largestBst(root->left), 
               largestBst(root->right));
    	//Your code here
    }
};