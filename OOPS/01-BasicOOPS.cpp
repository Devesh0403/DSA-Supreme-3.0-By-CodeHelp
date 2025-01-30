// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class Teacher{
    //PROPERTIES/ATTRIBUTES
    private:
    double salary;
    
    public:
    string name;
    string dept;
    string subject;
    
    //Non Parameterized
    Teacher(){
        cout<<"Constructor called"<<endl;
    }
    // Parameterized
    // Teacher(string n,string d,string s, int sal){
    //     name=n;
    //     dept=d;
    //     subject=s;
    //     salary=sal;
    // }
    
    //This Pointer
    Teacher(string name,string dept,string subject, int salary){
        this->name=name;
        this->dept=dept;
        this->subject=subject;
        this->salary=salary;
    }
    
    //Custom Copy Constructor
    Teacher(Teacher &obj){
        
        cout<<"Custom Copy Constructor Called"<<endl;
        this->name=obj.name;
        this->dept=obj.dept;
        this->subject=obj.subject;
        this->salary=obj.salary;
        
    }
    //METHODS// MEMBER FUNCTIONS
    void changeDept(string newDept){
        dept=newDept;
        
    }
    void setSalary(double sal){
        salary=sal;
    }
    
    void getSalary(){
        cout<<salary;
    }
    void getInfo(){
        cout<<name<<endl;
        cout<<dept<<endl;
        cout<<subject<<endl;
        cout<<salary<<endl;
        
    }
    ~Teacher(){
        cout<<"Destructor Called"<<endl;
    }
    
};
class Student{
    
    public:
    string name;
    string dept;
    int rollNo;
};

int main() {
    
    
    
    Teacher t1("Abhay","IT","DBMS",100000);
    // Teacher t2(t1);//Copy Constructor Invoking
    // t2.getInfo();
    
    
    return 0;
    
    
    
    
    
}