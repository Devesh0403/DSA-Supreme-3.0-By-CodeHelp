// METHOD 1 - Using Map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;
        ListNode* temp=head;

        while(temp){
            if(mp.find(temp)!=mp.end())return temp;

            else mp[temp]=true;

            temp=temp->next;
        }
        return NULL;
        
        
    }
};
// TC - O(N) [Single Linear Traversal]
// SC - O(N) [For Map]


// METHOD 2 - Tortoise Hare Method
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast){
            fast=fast->next;
            if(fast){
                slow=slow->next;
                fast=fast->next;

                if(slow==fast){
                    slow=head;
                    while(fast!=slow){
                        fast=fast->next;
                        slow=slow->next;
                    }
                    return slow;
                }


            }
        
        }
        return NULL;
        
    }
};
// TC - O(N) [Single Linear Traversal]
// SC - O(1) 
