// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<map>
#include<unordered_map>

int main() {
    
    unordered_map<int,string>uMap;
    map<int,string>oMap;
    
    uMap[1]="Scorpio";
    uMap[2]="Baleno";
    uMap[3]="Fortuner";
    
    oMap[2]="Baleno";
    oMap[3]="Fortuner";
    oMap[1]="Scorpio";
    
    
    
    cout<<"Unordered Map"<<endl;
    
    for(auto i:uMap){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    
    cout<<endl;
    
    cout<<"Unordered Map"<<endl;
    for(auto i:oMap){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    
    cout<<endl;
    
    if(uMap.find(9)==uMap.end()){
        cout<<"Not found"<<endl;
    }
    
    cout<<endl;
    
    
    
    
    
}