// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node (int data1){
        data=data1;  
        next=nullptr; 

    }
};

int main() {
    Node* y= new Node(0);
    cout<<y->data;
}