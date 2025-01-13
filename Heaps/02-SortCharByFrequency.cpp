class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        unordered_map<char,int>mp;

        for(auto ch:s){
            mp[ch]++;
        }
        for(auto num:mp){
            pq.push({num.second,num.first});

        }
        s="";
        while(!pq.empty()){
            auto it=pq.top();
            char ch=it.second;
            int freq=it.first;
            
            string s1=string(freq,ch);
            s=s1+s;
            pq.pop();

        }
        return s;


        
    }
};