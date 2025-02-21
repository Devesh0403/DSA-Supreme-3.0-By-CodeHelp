// BRUTE FORCE - USING TWO STACKS
class Solution {
    public:
        string decodeString(string s) {
            stack<int> numStack;
            stack<char> charStack;
    
            string ans = "";
    
            for (int i = 0; i < s.size(); i++) {
                int cnt = 0;
                if (s[i] >= '0' && s[i] <= '9') {
                    while (s[i] >= '0' && s[i] <= '9') {
                        cnt = cnt * 10 + s[i] - '0';
                        i++;
                    }
                    i--;
                    numStack.push(cnt);
                }
    
                else {
                    if (s[i] == ']') {
                        string str = "";
                        string temp = "";
                        int num = numStack.top();
                        numStack.pop();
    
                        while (!charStack.empty() && charStack.top() != '[') {
                            temp = charStack.top() + temp;
                            charStack.pop();
                        }
                        charStack.pop();
                        for (int i = 0; i < num; i++)
                            str += temp;
    
                        for (int j = 0; j < str.length(); j++)
                            charStack.push(str[j]);
                    } else {
                        charStack.push(s[i]);
                    }
                }
            }
    
            while (!charStack.empty()) {
                ans = charStack.top() + ans;
                charStack.pop();
            }
    
            return ans;
        }
    };

    
// TC - O(N)
// SC - O(N)