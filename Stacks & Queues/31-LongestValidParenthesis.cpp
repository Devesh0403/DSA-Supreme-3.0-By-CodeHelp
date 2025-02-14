class Solution {
    public:
      int maxLength(string& s) {
          stack<int>st;
          st.push(-1);
          int maxLen=0;
          
          for(int i=0;i<s.size();i++){
              if(s[i]=='(')st.push(i);
              
              else{
                  st.pop();
                  if(st.empty())st.push(i);
                  else{
                      maxLen=max(maxLen,i-st.top());
                  }
              }
          }
          return maxLen;
          // code here
      }
  };

  // TC - O(2*N)
  // SC - O(N)


  class Solution {
    public:
        int longestValidParentheses(string s) {
            int open=0;
            int close=0;
            int maxLen=0;
    
            for(int i=0;i<s.size();i++){
                if(s[i]=='(')open++;
                else if(s[i]==')')close++;
    
                if(open==close)maxLen = max(maxLen, 2 * close);
    
                if(close>open)close=open=0;
            }
            open=0; close=0;
    
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='(')open++;
                else if(s[i]==')')close++;
    
                if(open==close)maxLen = max(maxLen, 2 * open);
    
                if(open>close)close=open=0;
            }
            return maxLen;
            
        }
    };

    // TC - O(2*N)
    // SC - O(1)