// METHOD -1 Find Length of Linked List
class Solution {
public:
int getLength(ListNode* head){
    ListNode* temp=head;
    int count=0;
    while(temp){
        temp=temp->next;
        count++;
        
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        int len=getLength(head);
        if (n > len) return head; 
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* temp=head;
        for(int i=0;i<len-n-1;i++){
            temp=temp->next;
        }
      
        temp->next=temp->next->next;
        
        return head;

        
    }
};

// METHOD -2 Using Slow & Fast pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* fast=dummy;
        ListNode* slow=dummy;

        while(n--){
            fast=fast->next;

        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;

        }
        slow->next=slow->next->next;
        return dummy->next;
        
    }
};