// 1st solution 
// Using map O(n^2)

#include<iostream>
#include<map>
using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
        unordered_map<char,int>mp;
        string str="";
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            mp[ch]++;
            
            char ans='#';
            for(int k=0;k<=i;k++){
                char c=s[k];
                if(mp[c]==1){
                    ans=c;
                    break;
                }
            }
            str.push_back(ans);
        }
        return str;
       
    }
};

//2nd Solution
// Using map O(n)

#include <iostream>
using namespace std;
#include<map>

// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
        unordered_map<char,int>mp;
        string str="";
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            mp[ch]++;
            
            char ans='#';
            for(int k=0;k<=i;k++){
                char c=s[k];
                if(mp[c]==1){
                    ans=c;
                    break;
                }
            }
            str.push_back(ans);
        }
        return str;
        
    }
};


