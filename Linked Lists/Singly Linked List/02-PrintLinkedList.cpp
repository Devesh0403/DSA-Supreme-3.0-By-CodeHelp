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
int getLength(Node* head){
    Node* temp=head;
    int count=0;
    while(temp){
        temp=temp->next;
        count++;
        
    }
    return count;
}
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head= new Node(0);
    head->next=new Node(1);
    head->next->next=new Node(2);
    head->next->next->next=new Node(3);
    
    printLL(head);
    cout<<endl;
    cout<<getLength(head);
}