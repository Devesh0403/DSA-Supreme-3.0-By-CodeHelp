class Solution {
public:
    void partitionHelper(string s,int index,vector<vector<string>>&ans,vector<string>&path){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index, i - index + 1));
                partitionHelper(s,i+1,ans,path);
                path.pop_back();

            }
        }

    }
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>path;
        int index=0;

        partitionHelper(s,index,ans,path);
        return ans;


        
    }
};
// Time Complexity: O( (2^n) *k*(n/2) )
// Space Complexity: O(k * x)