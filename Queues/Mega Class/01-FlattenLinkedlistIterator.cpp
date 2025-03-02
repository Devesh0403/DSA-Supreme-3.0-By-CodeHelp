
 class NestedIterator {
    public:
        queue<int>q;
        void flatten(vector<NestedInteger>&nestedList){
            for(NestedInteger& item:nestedList){
                if(item.isInteger())
                    // for now, item is an instance of NestedInteger class
                    q.push(item.getInteger());
                else
                    flatten(item.getList());
            }
        }
        NestedIterator(vector<NestedInteger> &nestedList) {
            flatten(nestedList);
        }
        
        int next() {
            int front = q.front();
            q.pop();
            return front;
            
        }
        
        bool hasNext() {
            return !q.empty();
            
        }
    };
// TC - O(N)
// SC - O(N)