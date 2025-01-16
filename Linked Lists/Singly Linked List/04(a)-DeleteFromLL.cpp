// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.
class Solution {
public:
    void deleteNode(ListNode* node) {

        node->val=node->next->val;
        node->next=node->next->next;
        
    }
};