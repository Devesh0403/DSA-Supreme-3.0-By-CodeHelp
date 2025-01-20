/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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