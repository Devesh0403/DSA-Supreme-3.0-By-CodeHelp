void insert(stack<int> &st, int element) {
    if (st.empty() || element > st.top()) {
        st.push(element);
    } else {
        int temp = st.top();
        st.pop();
        insert(st, element);
        st.push(temp);
    }
}
void SortedStack :: sort()
{
    if(s.size()<=1)return;
    int top=s.top();
    s.pop();
    sort();
    insert(s,top);
    return ;
    
   //Your code here
}

//  TC - O(N^2)
// SC - O(N)

