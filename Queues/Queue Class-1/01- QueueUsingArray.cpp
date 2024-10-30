// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <queue>

class Queue{
        private:
        int* arr;
        int size;
        int front;
        int rear;
    public:
    Queue(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
    }
    void push(int val){
        //Overflow Condition
        if(rear==size-1){
            cout<<"Overflow"<<endl;
        }
        //Empty Queue
        else if(front==-1&&rear==-1){
            rear++;
            front++;
            arr[rear]=val;
            
            
        }
        //Normal insertion
        else{
            rear++;
            arr[rear]=val;
        }
        
        
    }
    void pop(){
        //Underflow condition
        if(front==-1&&rear==-1){
            cout<<"Underflow";
        }
        // One element
        else if(front==rear){
            arr[rear]=-1;
            rear=-1;
            front=-1;
            
        }
        //Normal pop
        else{
            arr[front]=-1;
            front++;
        }
        
    }
    bool isEmpty(){
        //If front and rear are still at -1 then the queue is empty.
        if(front==-1&&rear==-1){
            return true;
        }
        return false;
        
    }
    int getFront(){
        if(front==-1){
            cout<<"Queue is empty";
        }
        else{
            return arr[front];
        }
        
    }
    
    int getRear(){
        if(rear==-1){
            cout<<"Queue is empty";
        }
        else{
            return arr[rear];
        }
        
    }
    int getSize(){
        //return the size of the queue
        if(front==-1&&rear==-1){
            return 0;
        }
        return rear-front+1;
        
    }
    };

int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout<<q.getSize();
    
    q.pop();
    cout<<q.getSize();
    cout<<q.isEmpty();
    
}