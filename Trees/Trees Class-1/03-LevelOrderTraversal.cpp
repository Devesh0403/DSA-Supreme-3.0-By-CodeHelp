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

void levelOrderTraversalWithEOL(Node* root){
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    //push the root
    
    // add the elements to the queue
    // till it is empty
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                
            }
            
        }
        else{
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

int main() {
    Node * root;
    root=root->createTree();
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1
    levelOrderTraversal(root);
    
    
    
}