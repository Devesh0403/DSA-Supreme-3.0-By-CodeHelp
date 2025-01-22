class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        
        Node* head=new Node(arr[0]);
        Node* temp=head;
        
        for(int i=1;i<arr.size();i++){
            Node* curr=new Node(arr[i]);
            curr->prev=temp;
            temp->next=curr;
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
        // code here
    }
};