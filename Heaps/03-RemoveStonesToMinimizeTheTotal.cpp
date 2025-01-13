class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        priority_queue<int>pq;
        for(auto num:piles)pq.push(num);

        while(k--){
            int top=pq.top();
            pq.pop();
            top=top%2==0?top/2:top/2+1;
            pq.push(top);
        }

        int ans=0;
        while(!pq.empty()){
            cout<<pq.top();
            ans+=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};