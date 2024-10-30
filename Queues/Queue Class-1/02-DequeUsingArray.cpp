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
        //Overflow
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
        else if(front==rear){
            arr[rear]=-1;
            rear=-1;
            front=-1;
            
        }
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
    
class Deque{
    private:
    int *arr;
    int size;
    int front;
    int rear;
    
    public:
    Deque(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
        
    }
    void pushFront(int val){
        //Overflow condition
        if(front==0){
            
            cout<<"Overflow"<<endl;
        }
        
        //Empty Queue
        else if(front==-1&&rear==-1){
            front++;
            rear++;
            arr[front]=val;
            
        }
        //Normal Condition
        else{
            front--;
            arr[front]=val;
        }
        
        
        
    }
    void pushBack(int val){
        
        if(rear==size-1){
            cout<<"Overflow";
        }
        else if(front==-1&&rear==-1){
            rear++;
            front++;
            arr[rear]=val;
            
        }
        else{
            rear++;
            arr[rear]=val;
        }
        
    }
    void popFront(){
        if(front==-1&&rear==-1){
            cout<<"underflow";
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
            
        }
        //Normal flow
        else{
            arr[front]=-1;
            front++;
        }
        
    }
    void popBack(){
        //Underflow condition
        if(front==-1&&rear==-1){
            cout<<"Underflow"<<endl;
        }
        
        //Single element
        if(front==rear){
            arr[rear]=-1;
            front--;
            rear--;
        }
        
        //Normal
        else{
            arr[rear]=-1;
            rear--;
        }
        
        
    }
    // void print(){
    //     for(int i=0;i<arr.size();i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    // }
};

int main() {
    Deque dq(5);
    dq.pushFront(10);
    dq.pushBack(20);
    dq.popBack();
    dq.popBack();
    dq.popBack();
    
    
    
    
    
    
}