
#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int size;
    
    public:
    Stack(int num){
        size=num;
        arr=new int[size];
        top=-1;
    }
    void push(int num){
        if(top>=size)return;
        top++;
        arr[top]=num;
        // TIME COMPLEXITY- 0(1)
    }
    void pop(){
        if(top==-1)return;
        cout<<arr[top]<<endl;
        arr[top]=-1;
        top--;
        // TIME COMPLEXITY- 0(1)
    }
    int peek(){
        if(top==-1)return -1;
        return arr[top];
        // TIME COMPLEXITY- 0(1)
    }
    int getSize(){
        return top+1;
        // TIME COMPLEXITY- 0(1)
    }
    
};


int main() {
    Stack s(20);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    s.pop();
    s.peek();
    

    return 0;
}