// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int start;
    int end;
    int maxSize;
    int currSize;
    
    public:
    Queue(int num){
        maxSize=num;
        currSize=0;
        arr=new int[num];
        start=-1;
        end=-1;
    }
    void push(int num){
        if(currSize==maxSize){
            cout<<"Overflow"<<endl;
            return;
        }
        
        if(end==-1){
            end=0;
            start=0;
            
        }
        else{
            end=(end+1)%maxSize;
        }
        arr[end]=num;
        currSize++;
        // TIME COMPLEXITY- 0(1)
    }
    void pop(){
        if(currSize==0){
            cout<<"Underflow"<<end;
            return;
        }
        if(currSize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%maxSize;
            
        }
        arr[start]=-1;
        currSize--;
        // TIME COMPLEXITY- 0(1)
    }
    void peek(){
        if(start==-1){
            cout<<"No elements"<<endl;
        }
        cout<<arr[start]<<endl;
        // TIME COMPLEXITY- 0(1)
    }
    int getSize(){
        return currSize;
        // TIME COMPLEXITY- 0(1)
    }
    
};


int main() {
    Queue q(10);
    q.push(10);
    q.peek();
    

    return 0;
}