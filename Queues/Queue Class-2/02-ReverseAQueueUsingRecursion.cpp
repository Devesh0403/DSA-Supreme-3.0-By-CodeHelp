
#include <iostream>
#include <queue>
#include <stack>
using namespace std;



void reverseQueueUsingRecursion(queue<int>&q){

    //if empty, then return
    if(q.empty()){
        return;
    }
    //get the front element
    int frontElement=q.front();

    //pop the front element
    q.pop();

    //recursively call the function
    reverseQueueUsingRecursion(q);
    
    //push the frontElement 
    q.push(frontElement);
    
    
}

int main() {
    //Create a queue
    queue<int>q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    reverseQueueUsingRecursion(q);
    
    //printing the reversed queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    
}