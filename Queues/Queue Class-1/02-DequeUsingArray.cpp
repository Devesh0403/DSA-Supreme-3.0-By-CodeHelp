
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
        //overflow condition
        if(rear==size-1){
            cout<<"Overflow";
        }
        //empty queue
        else if(front==-1&&rear==-1){
            rear++;
            front++;
            arr[rear]=val;
            
        }
        //Normal case
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
        
        //Normal case 
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