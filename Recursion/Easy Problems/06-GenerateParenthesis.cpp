class Solution {
public:
    void generate(int n,int open,int close,vector<string>&ans,string str){
        if(open==n && close==n)ans.push_back(str);


        if(open<n)generate(n,open+1,close,ans,str+'(');
        if(close<open)generate(n,open,close+1,ans,str+')');
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0;
        int close=0;


        generate(n,open,close,ans,"");
        return ans;
        
    }
};

// TC - O(2^N)
// SC - O(N) [RECURSIVE]