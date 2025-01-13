//METHOD 1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mp;

        for(auto num:nums){
            mp[num]++;
        }

        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto it:mp){
            int freq=it.second;
            int num=it.first;

            pq.push({freq,num});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;




        
    }
};