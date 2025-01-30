// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
    string name;
    int age;
    
    Person(){
        cout<<"Person Constructor"<<endl;
    }
    Person(string name,int age){
        cout<<"Person Constructor"<<endl;
        this->name=name;
        this->age=age;
    }
};

class Student:public Person{
    public:
    int rollNo;
    
    Student(string name,int age,int rollNo):Person(name,age){
        
        cout<<"Student Constructor"<<endl;
        this->rollNo=rollNo;
        
    }
    
    
    void getInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<rollNo<<endl;
        
    }
    
};

int main() {
    Student s1("rahul",20,100);
  
    s1.getInfo();

    return 0;
}