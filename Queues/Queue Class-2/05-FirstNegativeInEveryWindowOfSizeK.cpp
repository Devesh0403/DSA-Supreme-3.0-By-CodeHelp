class Solution {
    public:
      vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
          
          vector<int>ans;
          queue<int>q;
          
          for(int i=0;i<k;i++){
              if(arr[i]<0)q.push(i);
          }
          
          if(q.empty()) {
              ans.push_back(0);
          }
          else {
              ans.push_back(arr[q.front()]);
          }
          
          for(int i=k;i<arr.size();i++){
              if(!q.empty()&&q.front()<i-k+1){
                  q.pop();
              }
              
              if (arr[i] < 0) q.push(i);
              
              if(q.empty()){
                  ans.push_back(0);
              }
              else{
                  ans.push_back(arr[q.front()]);
                  
              }
              
          }
          return ans;
          // write code here
      }
  };