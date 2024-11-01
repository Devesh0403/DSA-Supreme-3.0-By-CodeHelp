
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


void reverseInKGroups (queue<int> &q,int k,int count){
    
    //if count>k that means that the elements can be reversed, so follow the steps
    // 1. use a loop to iterate k times
    //    - pop an element from the queue in each iteration 
    //    - add the element to a stack
    // 2. again use a loop to iterate k times
    //    - pop the element from the stack 
    //    - add the element to the queue end

    if(count>=k){
        stack<int>st;
    
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
             
         }
        while(!st.empty()){
            int topElement=st.top();
            q.push(topElement);
            st.pop();
            
        }
        reverseInKGroups(q,k,count-k);
        
        
    }
    // if count>k that means the elements arent enough to be reversed, so pop these elements and add them to the queue end
    else{
        for(int i=0;i<count;i++){
            int element=q.front();
            q.pop();
            q.push(element);
            
        }
        
        
    }
    
   
    
    
    
    
}

int main() {
    //Create a queue
    queue<int>q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    
    int k=2;
    int count=q.size();
    reverseInKGroups(q,k,count);
    
    //printing the reversed queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    
}