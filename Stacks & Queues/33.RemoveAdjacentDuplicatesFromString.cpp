class Solution {
    public:
      string removeUtil(string &s) {
          string ans="";
          for(int i=0;i<s.size();i++){
              if(ans.empty()||ans.back()!=s[i]){
                  ans.push_back(s[i]);
              }
              else if(ans.back() == s[i]){
                  ans.pop_back();
              }
              
          }
          return ans;
          // code here
      }
  };

  // DOESNT WORK FOR MULTIPLE ADJACENT DUPLICATES

  