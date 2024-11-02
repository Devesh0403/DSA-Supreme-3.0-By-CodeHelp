
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>&q){
    stack<int>st;
    //O(n) space complexity
    
    while(!q.empty()){
        int element=q.front();
        st.push(element);
        q.pop();
        
        
    }
    //O(n) time complexity
    
    while(!st.empty()){
        int element=st.top();
        st.pop();
        q.push(element);
    }
    //O(n) time complexity
}

int main() {
    //Create a queue
    queue<int>q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    reverseQueue(q);
    
    //printing the reversed queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    
}