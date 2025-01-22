
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == NULL || head->next == NULL) {
        return head; 
        }
        
        DLLNode* curr=head;
        DLLNode* prev=NULL;
        
        while(curr){
            prev=curr->prev;
            curr->prev=curr->next;
            curr->next=prev;
            curr=curr->prev;
            
        }
        return prev->prev;
        
        // Your code here
    }
};


