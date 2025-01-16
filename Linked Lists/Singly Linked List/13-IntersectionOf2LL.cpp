// METHOD -1 Brute Using 2 Loops
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        while(temp1){
            ListNode* temp2=headB;
            while(temp2){
                if(temp1==temp2)return temp1;

                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return NULL;
        
    }
};
// TC - O(N^2) 
// SC - O(1)

// METHOD - 2 Using Map
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool>mp;
        while(headA){
            mp[headA]=true;
            headA=headA->next;
        }

        while(headB){
            if(mp.find(headB)!=mp.end())return headB;

            headB=headB->next;
        }
        return NULL;

        
    }
};

// TC - O(N) 
// SC - O(N)

// METHOD -3 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;  // Edge case: One or both lists are empty

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;  // Either the intersection node or nullptr
    }
};


//METHOD - 4 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* a=headA;
        ListNode* b=headB;

        while(a->next&&b->next){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }

             if(a->next==NULL){
                int bLen=0;

                while(b->next){
                    bLen++;
                    b=b->next;
                }
                while(bLen--){
                    headB=headB->next;
                }
            }
            else if(b->next==NULL) {
                int aLen=0;

                while(a->next){
                    aLen++;
                    a=a->next;
                }
                while(aLen--){
                    headA=headA->next;
                }
            }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
        
    }
};
