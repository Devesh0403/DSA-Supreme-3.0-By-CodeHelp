// Tortoise Hare Method 
class Solution {
  public:
    int findLength(Node* slow,Node* fast){
        int count=1;
        
            fast=fast->next;
        while(fast!=slow){
            fast=fast->next;
            count+=1;
        }
        
        return count;
    }
    int countNodesinLoop(Node *head) {
        
        Node* fast=head;
        Node* slow=head;
        
        while(fast!=NULL){
            fast=fast->next;
            
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            
            // When fast==slow traverse fast again till it becomes equal to slow
            if(fast==slow){
                int count=findLength(slow,fast);
                return count;
            }
        }
        return 0;
        
    }
};
