class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* temp=head;
        
        
        while(pos--){
            
            temp=temp->next;
            
        }
        Node* newNode=new Node(data);
        Node* forward=temp->next;
        
        if(temp->next==NULL){
            temp->next=newNode;
            newNode->prev=temp;
            
        }
        else{
            temp->next=newNode;
        newNode->prev=temp;
        newNode->next=forward;
        forward->prev=newNode;    
        }
        return head;
      
    }
};

