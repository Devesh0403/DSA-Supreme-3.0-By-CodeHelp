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
void insertAtHead(int val,Node* &head,Node* &tail){
    //if LL is empty
    if(head==NULL&&tail==NULL){
        Node* newNode=new Node(val);
        head=newNode;
        tail=newNode;
    }
    //if LL isn't empty
    else{
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
}
void insertAtTail(int val,Node* &head,Node* &tail){
    //if LL is empty
    if(head==NULL&&tail==NULL){
        Node* newNode=new Node(val);
        head=newNode;
        tail=newNode;
    }
    //if LL isn't empty
    else{
        Node* newNode=new Node(val);
        tail->next=newNode;
        tail=newNode;
    }
}
void insertAtPosition(int position,int val,Node* &head,Node* &tail){
    
    int len=getLength(head);
    //insert at head
    if(position == 1) {
    insertAtHead(val, head, tail);
    }
    //insert at tail
    else if(position == len + 1) {
    insertAtTail(val, head, tail);
    }
    else{
        Node* temp=head;
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
        Node* newNode=new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        
    }
}

void deleteNodeFromLL(int position,Node* &head,Node* &tail){
    if(head==NULL&&tail==NULL){
        cout<<"Empty Linked List"<<endl;
        
    }
    else if(head==tail){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else{
        if(position==1){
            Node* temp=head;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            Node* prev=head;
            for(int i=0;i<position-2;i++){
                prev=prev->next;
            }
            Node* curr=prev->next;
            Node* forward=curr->next;
            prev->next=forward;
            curr->next=NULL;
            delete curr;
        }
    }
    
}

int main() {
    Node* head= NULL;
    Node* tail=NULL;
    
    insertAtHead(10,head,tail);
    insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);
    
    insertAtTail(40,head,tail);
    insertAtTail(50,head,tail);
    insertAtTail(60,head,tail);
    
    insertAtPosition(4,0,head,tail);
    
    deleteNodeFromLL(3,head,tail);
    
    printLL(head);
    cout<<endl;
    cout<<getLength(head);
}