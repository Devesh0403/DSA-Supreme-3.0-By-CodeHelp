// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<queue>

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

Node* buildBST(Node* root,int val){
    
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    else{
        if(val<root->val){
            root->left=buildBST(root->left,val);
        }
        else{
            root->right=buildBST(root->right,val);
        }
    }
    return root;
}

Node* createTree(){
        cout<<"enter the value"<<endl;
        int val;
        cin>>val;
        Node* root=NULL;
        
        while(val!=-1){
            root=buildBST(root,val);
            cout<<"enter the value for new node"<<endl;
            cin>>val;
            
        }
        return root;
    }
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->val;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        
    }
    
}

int main() {
    Node* root=createTree();
    levelOrderTraversal(root);
    
    return 0;
    
    
}