//Solution 1
#include <vector>
using namespace std;
#include <iostream>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start=0;
        int balance=0;
        int deficit=0;

        for(int i=0;i<gas.size();i++){
            balance=balance+gas[i]-cost[i];

            if(balance<0){
                deficit+=abs(balance);

                start=i+1;
                balance=0;
            }
            
        }
        if(balance>=deficit){
            return start;
        }
        else{
            return -1;
        }
        
    }
    // 
};

