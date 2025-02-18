// BRUTE FORCE- USING 2 LOOPS

class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            vector<int>arr;
            while(head){
                arr.push_back(head->val);
                head=head->next;
    
            }
            vector<int>ans(arr.size(),0);
            for(int i=0;i<arr.size();i++){
                for(int j=i+1;j<arr.size();j++){
                    if(arr[j]>arr[i]){
                        ans[i]=arr[j];
                        break;
                    }
                }
            }
            return ans;
    
            
        }
    };

    // TC - O(N)+O(N^2)
    // SC - O(N)+O(N)

// METHOD -2 USING 2 LOOPS ( WITHOUT EXTRA SPACE )

class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            ListNode* temp=head;
            vector<int>ans;
    
            while(temp->next){
                ListNode* next=temp->next;
                while(next&&temp->val>=next->val){
                    next=next->next;
                }
                if(next&&next->val>temp->val)ans.push_back(next->val);
                else ans.push_back(0);
    
                temp=temp->next;
            }
            ans.push_back(0);
            return ans;
    
            
        }
    };

    // TC - O(N^2)
    // SC - O(N)






// METHOD - 3 USING STACK
class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            vector<int>arr;
            while(head){
                arr.push_back(head->val);
                head=head->next;
    
            }
            vector<int>ans(arr.size(),0);
            stack<int>st;
    
            for(int i=arr.size()-1;i>=0;i--){
                while(!st.empty()&&st.top()<=arr[i]){
                    st.pop();
    
                }
                if(!st.empty())ans[i]=st.top();
                st.push(arr[i]);
            }
            return ans;
    
            
        }
    };
// TC - O(N)
// SC - O(N)

