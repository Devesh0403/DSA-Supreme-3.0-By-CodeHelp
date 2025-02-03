// BRUTE FORCE 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        
        for(int i=0;i<s.size();i++){

            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(mp.size()==3){
                    ans+=s.size()-j;
                    break;
                }
            }
        }
        return ans;
        
    }
};
// TC - O(N^2)
// SC - O(N)

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int cnt=0;
        mp['a']=-1,mp['b']=-1,mp['c']=-1;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
            if(mp['a']!=-1&&mp['b']!=-1&&mp['c']!=-1){
                cnt+=1+min(mp['a'],min(mp['b'],mp['c']));
            }

            
        }
        return cnt;
        
    }
};
// TC - O(N)
// SC - O(3)~O(1)



class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0 ; 
        int right  = 0;
        int counter=0;
        map<char,int> mpp;
        while( right < n){
            mpp[s[right]]++;
            while(mpp.size() ==3){
                counter+= n - right;
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            right++;
        }
        return counter;
        
    }
};
// TC - O(N)
// SC - O(3)~O(1)