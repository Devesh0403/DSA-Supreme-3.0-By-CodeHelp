// METHOD 1 - Find Length of Linked List
class Solution {
public:
    int getLength(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||head->next==NULL)return NULL;
        int len=getLength(head);
        cout<<len;
        ListNode* temp=head;

        for(int i=0;i<len/2-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};

// TC- O(N)
// SC- O(1)


// METHOD - 2 Slow and Fast Pointers 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||!head->next)return NULL;
        

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;


        while(fast){
            fast=fast->next;

            if(fast){
                prev=slow;
                slow=slow->next;
                fast=fast->next;

            }
        }
        prev->next=slow->next;
        slow->next=NULL;
        delete slow;
        return head;

        
    }
};

// TC - O(N)
// SC- O(1)