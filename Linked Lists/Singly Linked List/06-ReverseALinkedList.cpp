// Method -1 Using extra Space (Stack)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        stack<ListNode*>st;

        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        head=st.top();
        temp=head;
        st.pop();
        while(!st.empty()){
            temp->next=st.top();
            st.pop();
            temp = temp->next;
            
        }
        temp->next=NULL;
        return head;
        
    }
};
// TC- O(N)+O(N)
// SC- O(N) [stack space]


// METHOD -2 Using 3 Pointers and No extra Space 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        return prev;
        
    }
};
// TC- O(N)
// SC- O(1) 

//METHOD -3 
