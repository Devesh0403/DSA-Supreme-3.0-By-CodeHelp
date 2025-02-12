// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
 public: 
    int val;
    Node *next;
    Node(int data)
    {
       val = data;
       next = nullptr;
    }
};  

class Queue{
    Node* front;
    Node* rear;
    int size;
    
    
    public:
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    void push(int x){
        Node* newNode=new Node(x);
        if(front==NULL){
            front=newNode;
            rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=rear->next;
        }
        size++;
        // TIME COMPLEXITY- 0(1)
    }
    int pop(){
        if (front == nullptr) {
            return -1; // Queue is empty
        }
        Node* temp = front;
        int poppedValue = temp->val;
        front = front->next;
        if (front == nullptr) {  
            rear = nullptr;
        }
        delete temp;  
        size--;
        return poppedValue;
        // TIME COMPLEXITY- 0(1)
        }
        
    int peek(){
        if(front==NULL)return -1;
        else return front->val;
        // TIME COMPLEXITY- 0(1)
    }
    int getSize(){
        return size;
        // TIME COMPLEXITY- 0(1)
    }
    
};


int main() {
    Queue q;
    q.push(10);
    q.push(20);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek();
    

    return 0;
}