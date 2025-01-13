class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;

        int start=0;
        int end=costs.size()-1;
        long long ans = 0;
        int cnt=0;

        while (cnt<k) {
            while(pq1.size()<candidates&&start<=end)pq1.push(costs[start++]);
            while(pq2.size()<candidates&&start<=end)pq2.push(costs[end--]);
            int a=pq1.size()>0?pq1.top():INT_MAX;
            int b=pq2.size()>0?pq2.top():INT_MAX;

            if(a<=b){
                ans+=a;
                pq1.pop();
            }
            else{
                ans+=b;
                pq2.pop();
            }
            cnt++;
            

        
        }
        
        return ans;



        
    }
};