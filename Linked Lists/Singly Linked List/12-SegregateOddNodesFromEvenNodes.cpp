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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);

        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;

        ListNode* curr = head;
        ListNode* temp;
        int index = 1;
        while (curr) {
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            if (index % 2 == 0) {
                evenTail->next = temp;
                evenTail = evenTail->next;
            } else {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            index++;
        }
        oddTail->next = evenHead->next;
        return oddHead->next;
    }
};
// TC- O(N)
// SC - O(1)