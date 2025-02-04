// METHOD - 1 ITERATIVE APPROACH
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        long ans=0;
        int sign=1;

        while(i<n&&s[i]==' ')i++;

        if(i<n && (s[i]=='-'||s[i]=='+')){
            sign=s[i]=='-'?-1:1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            // Step 4: Handle overflow
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            i++;
        }

        return sign*ans;

        
    }
};
// TC- O(N)
// SC- O(1)


// METHOD - 2 RECURSIVE APPROACH
class Solution {
public:
    int helper(string s,int i,long &ans,int &sign){
        if(i>=s.size()||!isdigit(s[i]))return sign*ans;

        ans=ans*10+(s[i] - '0');

        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;

        return helper(s,i+1,ans,sign);

    }
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        long ans=0;
        int sign=1;

        while(i<n&&s[i]==' ')i++;

        if(i<n && (s[i]=='-'||s[i]=='+')){
            sign=s[i]=='-'?-1:1;
            i++;
        }
        return helper(s, i, ans, sign);

        
    }
};





