//METHOD 1 - FINDING LENGTH OF LL FIRST
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
    ListNode* middleNode(ListNode* head) {
        int len=getLength(head);
        ListNode* temp=head;

        for(int i=0;i<len/2;i++){
            temp=temp->next;
        }
        return temp;


        
    }
};
// TC- O(N) + O(N/2) = O(N)
// SC- O(1)

//METHOD 2- TORTOISE HARE METHOD
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;

            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;

            }
            
        }
        return slow;
    }
};

//  TC- O(N) 
// SC- O(1)