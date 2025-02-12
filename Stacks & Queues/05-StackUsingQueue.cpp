class MyStack {
public:
    queue<int>q;
    int size;
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
        size++;
        
    }
    // Time Complexity: O(N)
    
    int pop() {
        int top=q.front();
        q.pop();
        size--;
        return top;
        
    }
    // Time Complexity: O(1)

    int top() {
        return q.front();
        
    }
    // Time Complexity: O(1)
    
    bool empty() {
        return size==0;
        
    }
};

// Time Complexity: O(N)

// Space Complexity: O(N)