#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int>ans;
        
        queue<int>q2;
        
        int n=q.size();
        
        int half=n/2;
        
        while(half--){
            int element=q.front();
            q.pop();
            q2.push(element);
            
            
        }
        
        int size=q.size();
        
        while(size--){
            ans.push_back(q2.front());
            q2.pop();
            ans.push_back(q.front());
            q.pop();
            
        }
        return ans;
    }
};



