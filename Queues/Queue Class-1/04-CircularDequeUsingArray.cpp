// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <queue>

class CircularDeque{
    
    private:
    int *arr;
    int size;
    int front;
    int rear;
    
    public:
    CircularDeque(int n){
        arr=new int[n];
        size=n;
        front=-1;
        rear=-1;
        
    }
    
    void pushFront(int val){
        //Overflow
        if((front==0 && rear==size-1)||rear==front-1){
            cout<<"Overflow"<<endl;
        }
        
        //Empty Queue
        else if(front==-1&&rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        
        //Circular case
        else if(front==0 && rear!=size-1){
            front=size-1;
            arr[front]=val;
        }
        
        // Normal case
        else{
            front--;
            arr[front]=val;
        }
        
        
        
    }
    void pushRear(int val){
        
        //Overflow
        if((front==0 && rear==size-1)||rear==front-1){
            cout<<"Overflow"<<endl;
        }
        
        //Empty Queue
        else if(front==-1&&rear==-1){
            front++;
            rear++;
            arr[rear]=val;
        }
        
        //Circular case
        else if(rear==size-1&&front!=0){
            rear=0;
            arr[rear]=val;
        }
        
        //Normal case
        else{
            rear++;
            arr[rear]=val;
        }
        
    }
    void popFront(){
        
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
    void popRear(){
        
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
        else if(rear==0){
            arr[rear]=-1;
            rear=size-1;
        }
        
        //Normal case
        else{
            arr[rear]=-1;
            rear--;
        }
        
        
        
        
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    
};
int main() {
    
    CircularDeque cq(6);
    
    cq.pushFront(10);
    cq.print();
    cq.pushRear(20);
    cq.print();
    cq.pushRear(30);
    cq.print();
    cq.pushRear(40);
    cq.print();
    
    cout<<cq.getSize()<<endl;
    
    cq.popFront();
    cq.print();
    cout<<cq.getSize()<<endl;;
    // cq.push(50);
}