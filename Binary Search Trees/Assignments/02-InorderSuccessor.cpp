/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
   
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        
       Node* ans=0;
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
       return ans;
    }
};