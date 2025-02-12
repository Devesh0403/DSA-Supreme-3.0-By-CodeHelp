class MyQueue {
public:
stack<int>st;
int size;
    MyQueue() {
        size=0;

        
    }
    void push(int x) {
        stack<int>st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        st.push(x);
        size++;

        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        
    }
    // Time Complexity: O(N)
    
    int pop() {
        int top=st.top();
        st.pop();
        size--;
        return top;
        
    }
    // Time Complexity: O(1)
    
    int peek() {
        return st.top();
        
    }
    // Time Complexity: O(1)
    
    bool empty() {
        return size==0;
        
    }
    // Time Complexity: O(1)
};

// Time Complexity: O(N)

// Space Complexity: O(N)
