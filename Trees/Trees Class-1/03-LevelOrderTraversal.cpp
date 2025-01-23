// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        this->data=val;
        left=NULL;
        right=NULL;
    }
    
    Node *createTree(){
        // cout<<"Enter the value for Node"<<endl;
        int value;
        cin>>value;
        
        if(value==-1){
            return NULL;
        }
        else{
            Node * root=new Node(value);
            // cout<<"adding left child for"<<value<<endl;
            root->left=createTree();
            
            // cout<<"adding right child for"<<value<<endl;
            root->right=createTree();
            
            return root;
        }
    }
};



void levelOrderTraversal(Node* root){
    queue<Node*>q;
    
    q.push(root);
    //push the root
    
    // add the elements to the queue
    // till it is empty
    while(!q.empty()){
        //obtain the front element and pop it
        Node* front=q.front();
        q.pop();
        
        //print the front element
        cout<<front->data<<" ";
        
        //if the front element has any children, push it to the queue
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
}

void levelOrderTraversalWithEOL(Node* root){
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    //push the root
    //push nULL value to the queue as well
    
    // add the elements to the queue
    // till it is empty
    while(!q.empty()){
        // if front element is NULL,pop it. if queue is empty
        if(q.front()==NULL){
            q.pop();
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                
            }
            
        }
        else if(q.front()!=NULL){
            Node* front=q.front();
            q.pop();
            cout<<front->data<<" ";
        
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
            
        }
        
    }
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == nullptr) {
            // If the tree is empty,
            // return an empty vector
            return ans; 
        }

        

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> level; 

            for(int i=0;i<size;i++){
                TreeNode* node = q.front(); 

                // Remove the front node from the queue
                q.pop(); 

                // Store the node value in the current level vector
                level.push_back(node->val); 

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }

            }
            ans.push_back(level);


            
        }
        return ans;
        
    }
};

int main() {
    Node * root;
    root=root->createTree();
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1
    levelOrderTraversal(root);
    
    
    
}