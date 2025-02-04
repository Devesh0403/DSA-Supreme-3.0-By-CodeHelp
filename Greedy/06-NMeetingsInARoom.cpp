struct Meet{
    int start;
    int end;
};
class Solution {
  public:
    static bool comp(Meet m1,Meet m2){
        return m1.end<m2.end;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        vector<Meet>v;
        for(int i=0;i<start.size();i++){
            v.push_back({start[i], end[i]});

        }
        
        sort(v.begin(),v.end(),comp);
        
        int ans=1;
        int limit=v[0].end;
        
        for(int i=1;i<v.size();i++){
            if(v[i].start>limit){
                ans++;
                limit=v[i].end;
            }
        }
        return ans;
        
        
        // Your code here
    }
};