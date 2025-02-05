class Solution{
public:
    void insertAtBottom(int num,stack<int>&st){
        if (st.empty()) {
            st.push(num);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(num, st);  // Recursive call to reach the bottom
        st.push(top);
        
        
    }
    void Reverse(stack<int> &st){
        if (st.empty()) return;  // Base case: empty stack

        int top = st.top();
        st.pop();  // Remove the top element

        Reverse(st);  // Recursively reverse the remaining stack

        insertAtBottom(top, st);  
    }
};