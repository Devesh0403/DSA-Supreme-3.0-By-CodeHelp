
bool isBalanced(string expr) {
    int count = 0;
    for (char c : expr) {
        if (c == '{') count++;
        else count--;
        if (count < 0) return false; 
    }
    return count == 0; 
}

void recur(string& expr, int n, int ind, int change, int& ans) {
    if (isBalanced(expr)) {
        ans = min(ans, change);  
        return;
    }
    if (ind == n) return;  

    
    recur(expr, n, ind + 1, change, ans);

    
    expr[ind] = (expr[ind] == '{') ? '}' : '{';
    recur(expr, n, ind + 1, change + 1, ans);

    
    expr[ind] = (expr[ind] == '{') ? '}' : '{';
}
int countRev (string expr)
{   
    int n = expr.length();
    if (n % 2 == 1) return -1;  
    int ans = INT_MAX;
    recur(expr, n, 0, 0, ans);  
    return ans;
}




int countRev (string s)
{   
    if(s.size()%2!=0){
        return -1;
    }
    int count=0;
    stack<char>st;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(!st.empty()&&st.top()=='{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
    }
    while(!st.empty()){
        char ch=st.top();
        st.pop();
        if(st.top()==ch){
            count++;
            st.pop();
        }
        else{
            count+=2;
            st.pop();
        }
    }
    return count;
    // your code here
}



int countRev (string expr)
{

    int n = expr.length();
    if (n % 2 != 0) return -1;  // If the length is odd, balancing is impossible

    int openCount = 0, closeCount = 0;

    for (char c : expr) {
        if (c == '{') {
            openCount++;
        } else {
            if (openCount > 0) {
                openCount--;  // Pairing with an open bracket
            } else {
                closeCount++;  // Extra closing bracket
            }
        }
    }

    // Calculate the minimum reversals
    return (openCount + 1) / 2 + (closeCount + 1) / 2;
  // your code here
}
    