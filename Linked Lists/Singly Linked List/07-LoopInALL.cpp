// METHOD 1 - Using Map
class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*,bool>mp;
        ListNode* temp=head;

        while(temp){
            if(mp.find(temp)!=mp.end())return true;

            else mp[temp]=true;

            temp=temp->next;
        }
        return false;
        
    }
};
// TC - O(N) [Single Linear Traversal]
// SC - O(N) [For Map]


// METHOD 2 - Tortoise Hare Method

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast){
            fast=fast->next;
            if(fast){
                slow=slow->next;
                fast=fast->next;

                if(slow==fast)return true;


            }
        
        }
        return false;
        
    }
};
// TC - O(N) [Single Linear Traversal]
// SC - O(1) 