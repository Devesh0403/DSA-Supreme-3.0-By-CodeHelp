// METHOD 1 - Using Stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*>st;

        ListNode* temp=head;

        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        temp=head;

        while(temp){
            if(temp->val!=st.top()->val)return false;

            temp=temp->next;
            st.pop();
        }
        return true;
        
    }
};
// TC - O(N) + O(N)
// SC - O(N) [Stack]


// METHOD 1 - Using Stack