// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <queue>

class CircularQueue{
    private:
    int *arr;
    int size;
    int front;
    int rear;
    
    public:
    CircularQueue(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
        
    }
    void push(int val){
        //Overflow
        if((front==0 && rear==size-1)||rear==front-1){
            cout<<"Overflow"<<endl;
        }
        
        //Empty Queue
        if(front==-1&&rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        
        //Circular case
        if(rear==size-1&&front!=0){
            rear=0;
            arr[rear]=val;
        }
        
        //Normal case
        else{
            rear++;
            arr[rear]=val;
        }
    }
    
    void pop(){
        
        //Underflow case
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
        }
        
        //Single element
        if(front==rear){
            arr[rear]=-1;
            front--;
            rear--;
            
        }
        
        //Circular case
        if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        
        //Normal Case
        else{
            arr[front]=-1;
            front--;
        }
        
        
    }
    
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    
    int getSize(){
        if(front==rear){
            return 0;
        }
        return abs(rear-front)+1;
    }
    
};
int main() {
    
    CircularQueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    // cq.push(50);
}