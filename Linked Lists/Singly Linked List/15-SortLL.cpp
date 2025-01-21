// METHOD 1 - Using Extra Space (Priority Queue)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;

        priority_queue<int, vector<int>, greater<int>>pq;
        ListNode* temp=head;
        while(temp){
            pq.push(temp->val);
            temp=temp->next;

        }
        head=new ListNode(pq.top());
        pq.pop();
        temp=head;

        while(!pq.empty()){
            int top=pq.top();
            ListNode* curr=new ListNode(top);
            temp->next=curr;
            temp=temp->next;
            pq.pop();
        }
        return head;
        
    }
};